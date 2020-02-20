#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int a[108], b[108], c[108];
int f[1002][1002];

int main()
{
	int i, bi, ci;
	
	scanf("%d %d %d", &n, &m, &x);
	for(i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	}
	
	for(i = 1; i <=n; i++)
		for(bi = m; bi >= b[i]; bi--)
			for(ci = x; ci >= c[i]; ci--) {
				f[bi][ci] = max(f[bi][ci],
					f[bi -b[i]][ci - c[i]] + a[i]);
			}
	
	printf("%d", f[m][x]);
	return 0;			 
}
