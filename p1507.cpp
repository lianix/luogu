#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int v, w, k, n;
int vv, ww, kk;
int f[406][406], ans;

int main()
{
	scanf("%d %d", &v, &w);
	scanf("%d", &n);
		
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d", &vv, &ww, &kk);
		for(int vi = v; vi >= vv; vi--)
			for(int wi = w; wi >=ww; wi--) {
				f[vi][wi] = max(f[vi][wi],
					f[vi-vv][wi-ww] + kk);
			}
	}
		
	
	printf("%d", f[v][w]);
	
	return 0;
} 
