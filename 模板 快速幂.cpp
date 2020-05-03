#include <bits/stdc++.h>
using namespace std;

long long a, p, m;

// a^p % m
long long qpow(long long a, long long p, long long m) 
{
	long long base = a;
	long long p1 = p;
	long long ans = 1;
	
	while(p1 > 0) {
		if( p1 & 1) {
			ans = ans * base;
			ans %= m;
		}
			
		base *= base;
		base %= m;
		p1 >>= 1;
	}
	
	return ans % m;
}

int main()
{
	scanf("%lld %lld %lld", &a, &p, &m);
	

	printf("%lld^%lld mod %lld=%lld", a, p, m, qpow(a, p, m));
	
	return 0;
}
