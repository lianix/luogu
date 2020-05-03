#include <bits/stdc++.h>
using namespace std;

int a[55][55]; 
int f[55][55][55][55];
int m, n;

int main()
{
	scanf("%d %d", &m, &n);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) { 
				for(int l = 1; l <= n; l++) {
					f[i][j][k][l] = max(max(f[i-1][j][k-1][l],
										   f[i-1][j][k][l-1]),
										max(f[i][j-1][k-1][l],
											f[i][j-1][k][l-1])) +
									a[i][j] + a[k][l];
					if(i == k && j == l)
						f[i][j][k][l] -= a[i][j];
				}
			}
		}
	}
	
	printf("%d", f[m][n][m][n]);
	return 0;
}
