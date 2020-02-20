#include <bits/stdc++.h>
using namespace std;

int n, m, k, r;
int ht[20], hs[20], tt[20];
int f[200];
int ttt;

int main()
{
	int i, t;
	scanf("%d %d %d %d", &n, &m, &k, &r);
	
	for(i = 1; i <= n; i++)
		scanf("%d", &tt[i]);
		
	for(i = 1; i <= m; i++)
		scanf("%d", &ht[i]);
		
	for(i = 1; i <= m; i++)
		scanf("%d", &hs[i]);
		
	for(i = 1; i <= m; i++)
		for(t = r; t >= ht[i]; t--)
			f[t] = max(f[t], f[t-ht[i]] + hs[i]);	

	for(t = 0; i <= r; t++)
		if ( f[t] >= k)
			break;
	
	sort(tt+1, tt+n+1);
	
	ttt = r - t;
	
	for(i = 1; i <= n; i++) {
		ttt -= tt[i];
		if(ttt < 0)
			break;	
	}
		
	printf("%d", i - 1);
}

