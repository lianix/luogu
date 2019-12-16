#include <bits/stdc++.h>
using namespace std;

long long maxsum;
long long sum[200008];
int n;

int main()
{
	int i, tmp;
	
	maxsum = numeric_limits<long long>::min();
	sum[0] = numeric_limits<long long>::min();
	
	//freopen("testdata.in", "r", stdin);
	//freopen("testdata.out", "w", stdout);
	scanf("%d", &n);
	for(i = 1; i <=n; i++) {
		scanf("%lld", &sum[i]);
		tmp = sum[i] + sum[i-1];
		if(tmp <= sum[i-1]) {
			maxsum  = max(maxsum, sum[i-1]);
		}
		
		if(tmp > sum[i])
			sum[i] = tmp;
	}

	maxsum  = max(maxsum, sum[n]);
	
	printf("%lld", maxsum);
	
	return 0;
}
