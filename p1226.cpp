#include <bits/stdc++.h>
using namespace std;

long long b, p, k, ans = 1, base;

int main()
{
	scanf("%lld %lld %lld", &b, &p, &k);
	
	base = b;
	int p1 = p;
	while(p1 > 0) {
		if( p1 & 1) {
			ans = ans * base;
			ans %= k;
		}
			
		base *= base;
		base %= k;
		p1 >>= 1;
	}
	
	printf("%lld^%lld mod %lld=%lld", b, p, k, ans%k);
	
	return 0;
}
