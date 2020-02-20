#include <bits/stdc++.h>
using namespace std;

char a[1008][1008];
int ans, n, m;

void findhe(int i, int j) {
	if(i >= 3) {
		if(a[i-1][j] == 'e' &&
		   a[i-2][j] == 'h' &&
		   a[i-3][j] == 'e')
			ans++;
	}
	
	if(i <= n - 4) {
		if(a[i+1][j] == 'e' &&
		   a[i+2][j] == 'h' &&
		   a[i+3][j] == 'e')
			ans++;
	}
	
	if(j >= 3) {
		if(a[i][j-1] == 'e' &&
		   a[i][j-2] == 'h' &&
		   a[i][j-3] == 'e')
			ans++;
	}
	
	if(j <= m - 4) {
		if(a[i][j+1] == 'e' &&
		   a[i][j+2] == 'h' &&
		   a[i][j+3] == 'e')
			ans++;
	}
}

int main()
{
	int i, j;
	
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	
	for(i = 0; i < n; i++) 
		for(j = 0; j < m; j++) {
			if(a[i][j] == 'h') {
				findhe(i, j);
			}
		}
	
	printf("%d", ans);
	return 0;
}

