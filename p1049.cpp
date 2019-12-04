#include <bits/stdc++.h>
using namespace std;

int n, v, a[36];
bool f[36];
int vmin = 20000;
 
int dfs(int v, int idx)
{
	int i;
	if(v < vmin)
		vmin = v;
	for(i = idx; i < n; i++) {
		if(v >= a[i]) {
			dfs(v - a[i], i+1);
		} else
			continue;
	}
}

int main()
{
	scanf("%d %d", &v, &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	dfs(v, 0);
	
	printf("%d", vmin);
	
	return 0;
}
