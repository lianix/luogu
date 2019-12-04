#include<bits/stdc++.h>
using namespace std;

const int days = 10002;
const int maxm = 10002;
char a[days][maxm];
int n, m, k;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int i, j, day;
	for(i = 0; i < n; i++) {
		for(j = 1; j <= m; j++) {
			scanf("%d", &day);
			a[day][j] = 1;
		}
	}
	
	int cnt;
	for(i = 1; i <= k; i++) {
		cnt = 0;
		for(j = 1; j <= m; j++) {
			cnt += a[i][j];
		}
		printf("%d ", cnt);
	}
	
	return 0;
	
}
