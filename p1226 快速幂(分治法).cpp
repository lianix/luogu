#include<bits/stdc++.h>
using namespace std;

long long b, p, k, ans=1;

long long qpow(long long n, long long m)
{
	if(m == 0)
		return 1;

	if(m == 1)
		return n % k;

	long long tmp = qpow(n, m / 2);
	tmp  = (tmp * tmp) % k;
	
	if(m & 1)
		return (n * tmp) % k;
	else
		return tmp;
}

int main()
{
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, qpow(b, p) % k);
    return 0;
}
