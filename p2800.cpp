#include <bits/stdc++.h>
using namespace std;

const int N = 1000002;
int n, a[N], f1[N]/*jump*/, f2[N]/*climb*/;

int main()
{
	int i;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	f1[1] = 0;
	f2[1] = a[1];
	
	for(i = 2; i <=n; i++) {
		f1[i] = min(f2[i - 1], f2[i - 2]);
		f2[i] = min(f1[i - 1], f2[i-1]) + a[i];
	}
	
	int ans = min(f1[n], f2[n]);
	
	printf("%d", ans);
	return 0;
}
