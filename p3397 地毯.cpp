#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
int  n, m;
int s[MAXN][MAXN], d[MAXN][MAXN];

int main()
{
	int x1, y1, x2, y2;
	
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        d[x1][y1] += 1;
        d[x2+1][y1] -= 1;
        d[x1][y2+1] -= 1;
        d[x2+1][y2+1] += 1;
    }
    
    for(int x = 1; x <= n; x++) {
    	for(int y = 1; y <= n; y++) {
    		s[x][y] = s[x-1][y] + s[x][y-1] - s[x-1][y-1] + d[x][y];
			printf("%d ", s[x][y]);
		}
		
		printf("\n");
	}

    return 0;
}

