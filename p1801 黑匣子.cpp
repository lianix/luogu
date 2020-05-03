#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 2e5+2;

int n, m, a[MAXN], b[MAXN];

priority_queue<int, vector<int>, greater<int> > q;
priority_queue<int> q1;

int main()
{
	int i, j;
	    
	scanf("%d %d", &m, &n);
    for(i = 1; i <= m; i++) {
    	scanf("%d", &a[i]);
	}
    for(i = 1; i <= n; i++) {
    	scanf("%d", &b[i]);
	}
    
    i = 1;
    for(j = 1; j <= n; j++) {
        for(; i <= b[j]; i++) {
            q1.push(a[i]);
            if(q1.size() == j) {
            	q.push(q1.top());
				q1.pop();
			}	
        }
        printf("%d\n", q.top());
        q1.push(q.top());
		q.pop();
    }
    return 0;
}
