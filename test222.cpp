#include <bits/stdc++.h>
using namespace std;


const int MAXN = 2e5 + 2;
int a[MAXN];
int u[MAXN];
int n, m;
	
priority_queue <int, vector<int>, greater<int> > q1;
priority_queue <int> q2;

int main()
{
	int i;
	
	scanf("%d %d", &m, &n);
	
	for(i = 1; i <= m; i++) {
		scanf("%d", &a[i]);
	}
		
	for(i = 1; i <= n; i++) {
		scanf("%d", &u[i]);
	}
	
	i = 1; 
	for(int j = 1;  j <= n; j++) {
		for(; i <= u[j]; i++) {
			q2.push(a[i]);
			printf("insert top: %d size:%d \n", q2.top(), q2.size());
	
			if(q2.size() == j) {
				q1.push(q2.top());
				q2.pop();
				
				printf("q2: top: %d size:%d \n", q2.top(), q2.size());
				printf("q1: top: %d size:%d \n", q1.top(), q1.size());
	
			}
		}
		printf("end: top: %d size:%d \n", q1.top(), q1.size());
		printf("%d\n", q1.top());
		q2.push(q1.top());
		q1.pop();
		
	}
	
	return 0;
}
