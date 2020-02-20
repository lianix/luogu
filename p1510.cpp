#include <bits/stdc++.h>
using namespace std;

int v, n, c, k[10006], m[10006], totalk, maxk;
int f[10000006];

int main()
{
	int i, vi;
	
	memset(f, 0x7f, sizeof(f));
	
	scanf("%d %d %d", &v, &n, &c);
	
	f[0] = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &k[i], &m[i]);
		maxk = max(maxk, k[i]);
	}
	
	maxk = v + maxk;
	for(i = 1; i <= n; i++) {
		for(vi = maxk; vi >= k[i]; vi--)
			f[vi] = min(f[vi], f[vi - k[i]] + m[i]);		
	}
	
	int ans = 0x7f7f7f7f;
	for(vi = v; vi <= maxk; vi++) {
		ans = min(ans, f[vi]);
	}
	
	ans = c - ans;
	if(ans < 0)
		printf("Impossible");
	else
		printf("%d", ans);
		
	return 0;
} 
