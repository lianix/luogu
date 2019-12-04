#include <bits/stdc++.h>
using namespace std;

const int MAXN = 108;
int a[MAXN][MAXN];

int n, m, k;
int x, y;
int cnt;

int fire[][2] = {
{-2, 0},
{ -1, -1}, { -1, 0}, { -1, 1},
{ 0, -2}, { 0, -1}, {0, 0}, {0, 1},{0, 2},
{ 1, -1}, { 1, 0}, { 1, 1},
{2, 0},
};

int main()
{
	m = k = 0;
	scanf("%d %d %d", &n, &m, &k);
	int i;
	for(i=0; i < m; i++) {
		scanf("%d %d", &x, &y);
		//
		for(int i1=0; i1 < sizeof(fire)/sizeof(fire[0]); i1++){
			a[y+2 + fire[i1][0]][x+2+fire[i1][1]] = 1;
		}
	}
	
	for(i=0; i < k; i++) {
		scanf("%d %d", &x, &y);
		//
		for(int x1=-2; x1 <=2 ; x1++)
			for(int y1=-2; y1 <=2; y1++){
			a[x +2 + x1][y+2+y1] = 1;
		} 
	}
			
	int j;
	for(i=3; i <= n+2; i++) {
		for(j = 3; j<= n+2; j++) {
			if(a[i][j] == 0)
				cnt++;
		}		
	}
	
	printf("%d", cnt);	
	return 0;
}

