#include <bits/stdc++.h>
using namespace std;

int a[122][122], s[122][122];
int n, sum, ans = -0x7f7f7f;

int main()
{
	int i, j;
	
	cin >> n;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}
		
	for(int x1 = 1; x1 <= n; x1++)
		for(int y1 = 1; y1 <= n; y1++)
			for(int x2 = x1; x2 <= n; x2++)
				for(int y2 = y1; y2 <= n; y2++) {
					sum = s[x2][y2] - s[x2][y1-1] -
						  s[x1-1][y2] + s[x1-1][y1-1];
					ans = max(ans, sum);
				}
	
	printf("%d", ans); 
	return 0;
}

