#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

int m, n;
int s[10002], t[10002];
int f[10002];

int main()
{
	int mi, ni;
	scanf("%d %d", &m, &n);
	
	for(ni = 1; ni <= n; ni++)
		scanf("%d %d", &s[ni], &t[ni]);
	
	
	for(ni = 1; ni <= n; ni++) {
		for(mi = t[ni]; mi <= m; mi++) {
			f[mi] = max(f[mi], f[mi - t[ni]] + s[ni]);
		}
	}

	printf("%d", f[m]);
	
	return 0;
} 
