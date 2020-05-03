#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 2;
const int mod = 998244353;

int m,n,x,y;
int a[MAXN];

long long f[MAXN];
//int ans[MAXN];
long long ans;

int count(int num, int max) 
{	
	int i, j;
	long long sum = 0;
	
	if(num < 1)
		return 1;
	
	if(num  == 1)
		return max;
	
	memset(f, 0, sizeof(f));
	f[1] = 1;	
	for(i = 1; i <= num; i++) {
		for(int j = 2; j <= max; j++) {
			f[j] = f[j - 1] + f[j];
			f[j] %= mod;
		}
	}
	
	for(int j = 1; j <= max; j++) {
		sum += f[j];
		sum %= mod;
	}
	 2
	return sum;
}

int main()
{
	int i;
	
	freopen("city.in","r",stdin);
 	freopen("city.out","w",stdout);
 
	scanf("%d %d %d %d", &m, &n, &x, &y);
	
	for(i = 1; i <= m; i++) {
		int cnt1 = count(x - 1, i);
		int cnt2 = count(n - x, m - i + 1);
		int cnt3 = count(y - n - 1, m - i + 1);
		int cnt4 = count(2*n - y, i);
		ans += (long long) cnt1 * cnt2 * cnt3 * cnt4;
		ans %= mod;
	}
	
	printf("%lld", ans);

	return 0;
}
