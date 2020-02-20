#include <bits/stdc++.h>
using namespace std;

int n;
int a[100][100];

int main()
{
	int x, y, i;
	
	scanf("%d", &n);
	
	i = 1;
	
	for(x=0, y=n-1; x<n; x++) 
		a[x][y] = i++;
	
	for(x=n-1, y= n-2; y>=0; y--) 
		a[x][y] = i++;
	
	for(x=n-2, y=0; x>=0; x--) 
		a[x][y] = i++;
	
	for(x=0, y=1; y<= n-2; y++) 
		a[x][y] = i++;
	
	x = 1; y= n-2;
	while(i <= n*n) {
		while(a[x][y]==0) {
			a[x++][y] = i++;
		}
		x--; y--;
		while(a[x][y]==0) {
			a[x][y--] = i++;
		}
		x--; y++;
		while(a[x][y]==0) {
			a[x--][y] = i++;
		}
		x++; y++;
		while(a[x][y]==0) {
			a[x][y++] = i++;
		}
		x++; y--;
	}

	for(x=0; x<n; x++) {
		for(y=0; y<n; y++)
			printf("%3d ", a[x][y]);
		printf("\n");
	}
	
	return 0;
}
