#include <bits/stdc++.h>
using namespace std;

const int MOD = 100003;
long long m, n;

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
    scanf("%lld %lld", &m, &n);
    long long total = qpow(m, n, MOD);
    long long no = (m * qpow(m-1, n-1, MOD)) % MOD;
    
    printf("%lld", (MOD + total - no) % MOD);
    
    return 0;
}
