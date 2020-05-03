
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 122;

int a[MAXN][MAXN];
int s[MAXN][MAXN];
int n, ans = -0x7f7f7f7f;

int main()
{
	cin >> n;
	int x, y;
	for(int x = 1; x <= n; x++)
		for(y = 1; y <= n; y++) {
			cin >> a[x][y];
			s[x][y] = s[x-1][y] +
			           s[x][y-1]  -
			           s[x-1][y-1] +
					   a[x][y];
		}
		
		
	int x1, y1, x2, y2;
	for(x1 = 1; x1 <= n; x1++)
		for(y1 = 1; y1 <= n; y1++)
			for(x2 = x1; x2 <= n; x2++)
				for(y2 = y1; y2 <= n; y2++) {
					int sum = s[x2][y2] - s[x2][y1-1] -
							  s[x1-1][y2] + s[x1-1][y1-1];
					ans = max(ans, sum);		  
				}
				
	printf("%d", ans);
}
