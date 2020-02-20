#include <bits/stdc++.h>
using namespace std;

int n;
int a[100][100];
////需要天调试 
int main()
{
	int x, y, i;
	
	scanf("%d", &n);
	
	i = 1;
	
	while(i <= n*n){
		while((x<n) && a[x][y]==0) {
			a[x++][y] = i++;
		}
		x--;
		while((y>=-1) && a[x][y]==0) {
			a[x][y--] = i++;
		}
		y++;
		while((x>=-1) || a[x][y]==0) {
			a[x--][y] = i++;
		}
		x++;
		while((y<=n) || a[x][y]==0) {
			a[x][y++] = i++;
		}
		y--;	
	}

	for(x=0; x<n; x++) {
		for(y=0; y<n; y++)
			printf("%3d ", a[x][y]);
		printf("\n");
	}
	
	return 0;
}
