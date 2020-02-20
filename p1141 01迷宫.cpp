#include <bits/stdc++.h>
using namespace std;

char p[1006][1006];
int flag[1006][1006];
int n, m;
int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

int ans[1000002];
int num = 0;

int bfs(int x, int y)
{
	queue<int> qx;
	queue<int> qy;
	
	if(flag[x][y] != 0) {
		return ans[flag[x][y]];
	}
	
	num++;

	qx.push(x);
	qy.push(y);
	flag[x][y] = num;
		
	while(!qx.empty()) {
		int tx = qx.front();
		int ty = qy.front();
		qx.pop();
		qy.pop();
		ans[num]++;
		
		for(int i = 0; i < 4; i++) {
			x = tx + dir[i][0];
			y = ty + dir[i][1];
			
			if(x == 0 || y == 0)
				continue;
			if(x == n+1 || y == n+1)
				continue;
			
			if(p[x][y] != p[tx][ty]) {
				if(flag[x][y] == 0) {
					qx.push(x);
					qy.push(y);
					flag[x][y] = num;
				}
			}
		}				
	}
	
	return ans[num];
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%s", &p[i][1]);
	}
	
	int x, y;
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", bfs(x, y));
	}
	
	return 0;
}
