#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int chess[406][406];

int dir[8][2] = {
	{-1, -2}, {-1, 2},
	{-2, -1}, {-2, 1},
	{1, -2}, {1, 2},
	{2, -1}, {2, 1},
};

int n, m;

void bfs(int x, int y)
{
	queue<int> qx;
	queue<int> qy;
	int cnt, next_cnt;
	int step, i, j;
	
	qx.push(x);
	qy.push(y);
	next_cnt = 1;
	step = 0;
	
	chess[x][y] = step;
	
	while(next_cnt) {
		cnt = next_cnt;
		next_cnt = 0;
		
	//	printf("queue count:%d\n", cnt);
		step++;
		for(i = 1; i <= cnt; i++) {
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
	
			for(j = 0; j < 8; j++) {
				int tx = x + dir[j][0];
				int ty = y + dir[j][1];
				
				if(tx < 1 || ty < 1)
					continue;
				if(tx > n || ty > m)
					continue;
				
				if(chess[tx][ty] == -1) {
					chess[tx][ty] = step;
					qx.push(tx);
					qy.push(ty);
					next_cnt++;
				}
			}		
		}		
	}
}

int main()
{
	int x, y, i, j;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			chess[i][j] = -1;	
		}
	}
	
	bfs(x, y);
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			printf("%-5d", chess[i][j]);	
		}
		printf("\n");
	}
		
	return 0;
}
