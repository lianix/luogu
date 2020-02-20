#include <bits/stdc++.h>
using namespace std;

int maze[8][8];
int  n, m, t, cnt;
int sx, sy, fx, fy;

int dfs(int x, int y)
{
	if(x == fx && y == fy) {
		cnt++;
		return 0;
	}
	
	maze[x][y] = 1;
	if(maze[x+1][y] == 0)
		dfs(x+1, y);
	
	if(maze[x-1][y] == 0)
		dfs(x-1, y);
		
	if(maze[x][y+1] == 0)
		dfs(x, y+1);
		
	if(maze[x][y-1] == 0)
		dfs(x, y-1);
	
	maze[x][y] = 0;
}

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d %d", &sx, &sy, &fx, &fy);

	int i, x, y;
	for(i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		maze[x][y] = 2;
	}

	//±ß½ç
	for(x = 0; x <= n+1; x++) {
		maze[x][0] = 2;
		maze[x][m+1] = 2;
	} 
	
	for(y = 0; y <= m+1; y++) {
		maze[0][y] = 2;
		maze[n+1][y] = 2;
	}
	dfs(sx, sy);
	printf("%lld", cnt);
	return 0;
}
