#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

long long n, p;
long long ans = -0x47474747, f, pref;

int main()
{
	scanf("%lld", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &p);
		f = max(pref + p, p);
		ans = max(ans, f);
		pref = f;
	}
		
	
	printf("%lld", ans);
	
	return 0;
} 
