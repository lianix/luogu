#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
int n, m, c;
int a[MAXN][MAXN], s[MAXN][MAXN];
int x, y, ans = -0x7f7f7f7f;

int main()
{
	scanf("%d %d %d", &n, &m, &c);
	
	for(x = 1; x <= n; x++) {
		for(y = 1; y <= m; y++) {
			scanf("%d", &a[x][y]);	
			s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + a[x][y];
		}
	}
	

	for(int x1 = 1; x1 <= n - c + 1; x1++) {
		for(int y1 = 1; y1 <= m - c + 1; y1++) {
			int x2 = x1 + c - 1;
			int y2 = y1 + c - 1;
			int tmp = s[x2][y2] - s[x2][y1-1] -
					  s[x1-1][y2] + s[x1-1][y1-1];
			if(tmp  > ans) {
				x = x1;
				y = y1;
				ans = tmp;
			}	
		}	
	}
	
	printf("%d %d", x, y);
	
	return 0;
}
