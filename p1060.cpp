#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[30];
int b[30];
int tmax;

int dfs(int money, int idx, int total)
{
	if(total > tmax)
		tmax = total;

	for(int i = idx; i < m; i++) {
		if(money >= a[i])
			dfs(money - a[i], i+1, total+ a[i] * b[i]);
	}	
}

int main()
{
	scanf("%d %d", &n, &m);	
	for(int i = 0; i < m; i++)
		scanf("%d %d", &a[i], &b[i]);

	dfs(n, 0, 0);
	printf("%d", tmax);
		
	return 0;
} 
