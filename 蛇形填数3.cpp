#include <bits/stdc++.h>
using namespace std;

int n;
int a[100][100];

int main()
{
	int x, y, i, k;
	
	scanf("%d", &n);
	
	x = 0;
	y = n-1;
	i = 1;
	k = n-1;
	while(k >= 1 ) {
		int step = k;
		while(step--) {
			a[x++][y] = i++;
		}
		step = k;
		while(step--) {
			a[x][y--] = i++;
		}
		step = k;
		while(step--) {
			a[x--][y] = i++;
		}
		step = k;
		while(step--) {
			a[x][y++] = i++;
		}
		
		k = k - 2;
		x++;
		y--;
	}

	if(k == 0 ) {
		a[x][y] = i++;	
	}
	 
	for(x=0; x<n; x++) {
		for(y=0; y<n; y++)
			printf("%3d ", a[x][y]);
		printf("\n");
	}
		
	return 0;
}
