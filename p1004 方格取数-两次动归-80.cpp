#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int f[MAXN][MAXN];
int n, x, y, v, ans1, ans2;

int main()
{
	int i, j;
	scanf("%d", &n);
	while (1) {
		scanf("%d %d %d", &x, &y, &v);
		if( x== 0 && y == 0 && v == 0)
			break;
		a[x][y] = v;
		f[x][y] = v;
	}
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++) {
			f[i][j] += max(f[i-1][j], f[i][j-1]);
		}
#if 0
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");	
	}
#endif
	
	int route = f[n][n];
	for(i = n; i >= 1; i--)
		for(j = n; j >= 1; j--) {
			if(f[i][j] == route) {
				if(a[i][j]) {
					route -= a[i][j];
					a[i][j] = 0;
				}	
			} 
		}
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++) {
			a[i][j] += max(a[i-1][j], a[i][j-1]);
		}

	printf("%d\n", f[n][n] + a[n][n]) ;
	return 0;
}

