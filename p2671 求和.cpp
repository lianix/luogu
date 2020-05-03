#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
const int MOD = 10007;

int num[MAXN], color[MAXN];
int sum[MAXN][2], cnt[MAXN][2];
int n, m, ans;

int main() 
{
	int i;
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
		cnt[color[i]][i%2]++;
		sum[color[i]][i%2] += num[i];
		sum[color[i]][i%2] %= MOD;
	}
	
	for(int i = 1; i <= n; i++) {
		int p1 = ((cnt[color[i]][i%2] - 2) * num[i]) % MOD;
		p1 = (p1 + sum[color[i]][i%2]) % MOD;
		p1 = (i * p1) % MOD;
		ans = (ans + p1) % MOD;
	}
	
	printf("%d", ans);
	
	return 0;
}


