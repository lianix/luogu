#include <bits/stdc++.h>
using namespace std;

int chess[14][14];
int n;
long long cnt;
int ans[14];

inline bool attack(int row, int col)
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
	
	for(j = 1; j <= n; j++)	{
		if(attack(row, j)) {
			ans[row] = j;
			find(row+1);
			ans[row] = 0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	find(1);
	printf("%lld", cnt);
	return 0;
}
