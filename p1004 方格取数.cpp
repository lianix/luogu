#include <bits/stdc++.h>
using namespace std;

int a[12][12]; 
int f[12][12][12][12];
int n, x, y, v;

int main()
{
	scanf("%d", &n);
	while (1) {
		scanf("%d %d %d", &x, &y, &v);
		if( x== 0 && y == 0 && v == 0)
			break;
		a[x][y] = v;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) { 
				for(int m = 1; m <= n; m++) {
					f[i][j][k][m] = max(max(f[i-1][j][k-1][m],
										   f[i-1][j][k][m-1]),
										max(f[i][j-1][k-1][m],
											f[i][j-1][k][m-1])) +
									a[i][j] + a[k][m];
					if(i == k && j == m)
						f[i][j][k][m] -= a[i][j];
				}
			}
		}
	}
	
	printf("%d", f[n][n][n][n]);
	return 0;
}
