#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+2;

struct Picture {
	int painter;
	bool duplicate;
	Picture *next; 
};

Picture a[MAXN];
Picture *painter[2008];

int n, m, num, minl, minr, minlen = MAXN;

int main()
{
	int i;
	
	scanf("%d %d", &n, &m);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i].painter);
		a[i].next = NULL;
		a[i].duplicate = false;
	}
	
	int front = 1;
	int back;
	int num = 0;
	
	for(back = 1; back <= n; back++) {	
		Picture *p = &a[back];
		if(painter[p->painter] == NULL) {
			num++;
			painter[p->painter] = p;
		} else {
			Picture *tmp = painter[p->painter];
			tmp->duplicate = true;
			p->next = tmp;
			painter[p->painter] = p;
		}
		
		while(front < back) {
			if(a[front].duplicate == true)
				front++;
			else
				break;
		}
		
		if(num == m && (back - front + 1) < minlen) {
			minl = front;
			minr = back;
			minlen = back - front + 1;
		}
	}
	
	printf("%d %d\n", minl, minr);
	
	return 0;
}
