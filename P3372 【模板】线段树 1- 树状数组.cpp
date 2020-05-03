#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 2;
long long n, m, opt, x, y, k;
long long a[MAXN];
long long sum1[MAXN];    //(D[1] + D[2] + ... + D[n])
long long sum2[MAXN];    //(1*D[1] + 2*D[2] + ... + n*D[n])

long long lowbit(long long x) {
    return x&(-x);
}

void add(long long i, long long k) 
{
    long long x = k * (i-1);  
    while(i <= n){
        sum1[i] += k;
        sum2[i] += x;
        i += lowbit(i);
    }
}

long long sum(long long i)
{ 
    long long res = 0, x = i;
    while(i > 0){
        res += x * sum1[i] - sum2[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
	long long i;
	
    scanf("%lld %lld", &n, &m);
    for(i = 1; i <= n; i++) { 
        scanf("%lld", &a[i]);
        add(i, a[i] - a[i-1]);
    }

   	for(i = 1; i <= m; i++) {
		scanf("%lld %lld %lld", &opt, &x, &y);
		if(opt == 1) {
			scanf("%d", &k);
			add(x, k);
			add(y+1, -k);
		} else {
			printf("%lld\n", sum(y) - sum(x-1));
		}
	}
    return 0;
}
