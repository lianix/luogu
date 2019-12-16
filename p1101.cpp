#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;
char a[MAXN][MAXN];
char ans[MAXN][MAXN];
int n;
int dir[8][2] = { //0->ÐÐ, 1->ÁÐ 
{1, 0},
{-1, 0},
{0, 1},
{0, -1},
{-1, -1},
{-1, 1},
{1, -1},
{1, 1},
};

char word[] = "yizhong";
int len;

void dfs(int x, int y, int d)
{
	int sx = x;
	int sy = y;
	
	if(sx + dir[d][0] * (len - 1) > (n-1) ||
	   sx + dir[d][0] * (len - 1) < 0 )
		return;
		
	if(sy + dir[d][1] * (len - 1) > (n-1) ||
	   sy + dir[d][1] * (len - 1) < 0 )
		return;
		
	for(int i = 1; i < len; i++) {
		sx += dir[d][0];
		sy += dir[d][1];
		if(a[sx][sy] != word[i])
			return;
	}
	
	for(int i = 0; i < len; i++) {
		ans[x+ dir[d][0] * i ][y + dir[d][1] * i] = word[i];
	}
}

int main()
{
	int i;
	
	len = strlen(word);
	
	scanf("%d", &n);	
	for(i=0; i <n; i++) {
		scanf("%s", a[i]);
		memset(ans[i], '*', n);
	}
	
	int x, y;
	for(x=0; x<n; x++)
		for(y=0; y<n; y++) {
			if(a[x][y] == word[0]) {
				for(int d = 0; d < 8; d++)
					dfs(x, y, d);
			}		
		}
	
	for(i=0; i<n; i++) {
		printf("%s\n", ans[i]);
	}
	
	return 0;
}
