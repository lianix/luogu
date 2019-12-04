#include <bits/stdc++.h>
using namespace std;

int chess[14][14];
int n;
long long cnt;
int ans[14];

bool attack(int row, int col)
{
	for(int i = 1; i < row; i++) {
		if(ans[i] == col || (i+ans[i]) ==(row+col) ||
			(i-ans[i]) == (row-col))
			return false;
	}
	
	return true;
}

void find(int row)
{
	int i, j;
	if(row > n) {
		if(cnt < 3) {
			for(i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		cnt++;
		return;
	}
	
	for(j = 1; j <= n; j++)
	{
		if(attack(row, j)) {
			ans[row] = j;
			find(row+1);
			ans[row] = 0;
		}
	}
}

bool mask(int row, int col)
{
	int tmp[15][15];
	int i;
	//memcpy(tmp, chess, sizeof(chess));
	for(i = 1; i <= n; i++)
		chess[row][i] = 1;
	for(i = 0; i < n; i++)
		chess[i][col] = 1;
	for(i = 1; i < n; i++) {
		if(row+i > n || col+i > n)
			break;
		chess[row+ i][col + i] = 1;
	}
	for(i = 1; i < n; i++) {
		if(row - i < 1 || col - i < 1)
			break;
		chess[row - i][col - i] = 1;	
	}
	
	for(i = 1; i < n; i++) {
		if(row + i > n || col - i < 0)
			break;
		chess[row + i][col -  i] = 1;	
	}
	
	for(i = 1; i < n; i++) {
		if(row - i < 1 || col + i > n)
			break;
		chess[row - i][col + i] = 1;	
	}
}
 
int dfs(int row)
{
	int i, j;
	if(row > n) {
		if(cnt < 3) {
			for(i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		cnt++;
		return;
	}
	
	for(j = 1; j <= n; j++)
	{
		if(chess[row][j] == 1)
			continue;
		ans[row] = j;
		mask(row, j);
		find(row + 1);
	}
}

int main()
{
	scanf("%d", &n);
	find(1);
	printf("%lld", cnt);
	return 0;
}
