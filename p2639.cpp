#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int h, n;
int w[506];
int f[45002];

int main()
{
	int hi, ni;
	scanf("%d %d", &h, &n);
	
	for(ni = 1; ni <= n; ni++)
		scanf("%d", &w[ni]);
	
	for(ni = 1; ni <= n; ni++) {
		for(hi = h; hi >= w[ni]; hi--) {
			f[hi] = max(f[hi], f[hi - w[ni]] + w[ni]);
		}
	}

	printf("%d", f[h]);
	
	return 0;
} 
