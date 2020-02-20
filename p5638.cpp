#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e6)+ 1;
unsigned long long a[MAXN];
unsigned long long maxt;
unsigned long long sum[MAXN];
int n, k;

int main()
{
	int i;
	
	scanf("%d %d", &n, &k);
	for(i = 1; i < n; i++){
		scanf("%llu", &a[i]);
		sum[i] = sum[i-1] + a[i];
		if(i >= k) {
			maxt = max(maxt, sum[i] - sum[i-k]);
		}
	}

	printf("%llu", sum[n-1] - maxt);
	
	return 0;
}
