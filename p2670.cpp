#include <bits/stdc++.h>
using namespace std;

int a[106][106];
int m, n;
char b[106];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%s", &b[1]);
		for(int j = 1; j <= m; j++) {
			if(b[j] == '*') {
				a[i][j] = -100;
				
				a[i-1][j-1]++;
				a[i-1][j]++;
				a[i-1][j+1]++;	
							
				a[i][j-1]++;
				a[i][j+1]++;
				
				a[i+1][j-1]++;
				a[i+1][j]++;
				a[i+1][j+1]++;
			}
		}		
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] < 0)
				printf("*");
			else
				printf("%d", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
