#include <bits/stdc++.h>
using namespace std;

int a[40][40];
int n;

int main()
{
	scanf("%d", &n);
	int x, y;
	x = 1;
	y = n/2 + 1;
	a[x][y] = 1;
	for(int i = 2; i <= n*n; i++) {
		if(x == 1) {
			if(y != n) {
				x = n;
				y++;
				a[x][y] = i;
			} else {
				x++;
				a[x][y] = i;
			}
		} else {
			if(y == n) {
				y = 1;
				x--;	
			} else {
				if(a[x-1][y+1] == 0) {
					x--;
					y++;
				} else {
					x++;
				}
			}
		}
		
		a[x][y] = i;
	}

	for(x = 1; x <= n; x++) {
		for(y = 1; y <= n; y++)
			printf("%d ", a[x][y]);
		
		printf("\n");
	}
	
	return 0;
}

