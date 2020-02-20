#include<bits/stdc++.h>
using namespace std;

unsigned long long chess[26][26];
int ax, ay, bx, by;
int horse[][2]= {
{-2, 1}, {-2, -1}, {2,  1}, {2,  -1},
{1, -2}, {1,   2}, {-1, 2}, {-1, -2}
};

int main()
{
	int i, j;
	
	scanf("%d %d %d %d", &ax, &ay ,&bx, &by);

	ax+=1; ay+=1; 
	bx+=1; by+=1;
	
	chess[bx][by] = 1;
	for(i = 0; i < 8; i++) {
		int tbx = bx + horse[i][0];
		int tby = by + horse[i][1];
		if(tbx < 1 || tby < 1)
			continue;
		if(tbx > ax || tby > ay)
			continue;
		chess[tbx][tby] = 1;
	}
	
	chess[1][0] = 1;
	for(i = 1; i <= ax; i++) { 
		for(j = 1; j <= ay; j++) {
			if(chess[i][j]) {
				chess[i][j] = 0;
				continue;
			}
			chess[i][j] = chess[i-1][j] + chess[i][j-1]; 
		}
	}
	
	printf("%llu\n", chess[ax][ay]);
	
	return 0;
}
