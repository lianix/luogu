#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
long long a[MAXN], s[MAXN];
int n, k;
long long ans = -0x7f7f;

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i-1] + a[i];
		if(i >= k)
			ans = max(ans, s[i] - s[i - k]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
