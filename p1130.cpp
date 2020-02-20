#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2006][2006], f[2006][2006];
int ans = 0x7f7f7f7f;

int main()
{
	int ni, mi;
	 
	scanf("%d %d", &n, &m);
	for(mi = 1; mi <= m; mi++)
		for(ni = 1; ni <= n; ni++) {
			scanf("%d", &a[mi][ni]);
		}
		
	for(ni = 1; ni <= n; ni++)
		for(mi = 1; mi <= m; mi++) {
			int pre = mi - 1 ?  mi - 1 : m;
			f[ni][mi] = min(f[ni - 1][mi], f[ni - 1][pre]) + a[mi][ni];
		}
	
	for(mi = 1; mi <= m; mi++)
		ans = min(ans, f[n][mi]);
		
	printf("%d", ans);	
}

