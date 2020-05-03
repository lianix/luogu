#include <bits/stdc++.h>
using namespace std;

int n, p;
long long  f[506][506];
long long  ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		f[i][i] = 1; 
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j < i; j++) {
			for(int k = 1; k < j && j + k <= i; k++) {
				f[j][i] += f[k][i - j];
			}
			//printf("f[%d][%d] = %d\n", j, i, f[j][i] );
		}	
	}
	
	for(int i = 1; i<=n; i++) {
		ans += f[i][n];
	}
	
	printf("%lld", ans-1) ;
} 
