#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000002; 

int n;
char s[MAXN];

int ans[MAXN][2], idx;

struct Node {
	int l, r, v, d;
	int id;
	bool flag;
	bool removed;
} a[MAXN];

bool operator< (Node a1, Node a2)
{
	if(a1.d == a2.d)
		return a1.id < a2.id;
		
	return a1.d < a2.d;
}

priority_queue < Node > q;

int main() {
	
    scanf("%d", &n);
    scanf("%s", s);
    
    a[0].v = 0x7f7f7f7f;
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'B') {
            a[i]. flag= true;
        }
        else {
            a[i].flag = false;
        }
       
		scanf("%d", &a[i].v);
		
		a[i].id = i;
		a[i].d = abs(a[i].v - a[i-1].v);
		a[i].l = i - 1;
		a[i].r= i + 1;

		q.push(a[i]);
    }
    
    while(!q.empty())
    {
		int x = q.top().id; 
		q.pop(); 
		int y = a[x].l;
		a[y].removed = true; 

		if(a[x].removed == false && 
			a[x].flag != a[y].flag &&
			x != 0 &&
			y!= n+1) {
			
			idx++;
			ans[idx][0]=x;
			ans[idx][1]=y;
			
			a[a[x].r].l = a[y].l;
			a[a[y].l].r = a[x].r;
			a[a[x].r].d = abs(a[a[y].l].v -  a[a[x].r].v);
			
			if(a[y].l > 0 && a[x].r <= n) 
				q.push(a[a[x].r]);
				
			a[x].l=a[x].r=n+1; a[y].l=a[y].r=0;
		}
	}

	printf("%d\n", idx);
    for(int i = 1; i <= idx; i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);
        
    return 0;
}

