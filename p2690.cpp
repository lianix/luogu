#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int t, w;
int a[1002], f[32][1002];

int main()
{
	int ti, wi;
	scanf("%d %d", &t, &w);
	
	for(ti = 1; ti <= t; ti++)
		scanf("%d", &a[ti]);
	
	//wi = 0
	debug("\nw = 0:\n");
	for(ti = 1; ti <= t; ti++) {
		f[0][ti] = f[0][ti - 1];
		if(a[ti] == 1)
			f[0][ti] += 1;
		debug("%d", f[0][ti]);
	}

	for(wi = 1; wi <= w; wi++) {
		debug("\nw = %d:\n", wi);
		for(ti = 1; ti <= t; ti++) {
			f[wi][ti] = max(f[wi][ti - 1], f[wi - 1][ti - 1]);
			if(wi & 1) {
				if(a[ti] == 2)
					f[wi][ti] += 1;
			} else {
				if(a[ti] == 1)
					f[wi][ti] += 1;
			}
			debug("%d ", f[wi][ti]);	 
		} 
	}
		
	int ans = 0;
	for(wi = 0; wi <= w; wi++) {
		ans =max(ans, f[wi][t]);
	}
	
	printf("%d", ans);
	
	return 0;
} 
