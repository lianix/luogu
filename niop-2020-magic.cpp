#include<bits/stdc++.h>
using namespace std;

#define MAX 102
#define MAXN 1e9

int cost[MAX][MAX];
int dist[MAX], path[MAX], s[MAX], cc[MAX];
int n, m, k, minc;
 
int main()
{
	int x, y, c, i, j;

	scanf("%d %d %d",&n,&m, &k);
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		cost[x][y] = c;		
	}
	
	for(x=1; x<=n; x++) {
		dist[x] = cost[1][x];
		if(dist[x] == 0)
			dist[x] = MAXN;
		s[i] = 0;
	}
	
	s[1] = 1;
	dist[1] = 0;
	
	for(i=1; i<=n; i++)
	{
		x = 0;
		minc = MAXN;
		for(j = 1; j <= n; j++)
		{
			if(s[j]==0)
			{
				if(dist[j] < minc && dist[j]!=0)
				{
					minc = dist[j];
					x = j;
					if(i == 1)
						path[i] = x;
				}
			}
		}
		if(x == 0)
		{
			break;
		}
		
		s[x] = 1;
		for(j = 1; j <= n; j++)
		{
			if(cost[x][j] != 0 && cost[x][j] < MAXN)
			{
				if(cost[x][j] + dist[x] < dist[j])
				{
					dist[j] = cost[x][j] + dist[x];
					path[x] = j;
				}
			}
		}
	}

	//printf("%d\n", dist[n]);
	
	x = 1;
	for(int i = 1; i < n; i++) {
		cc[i] = cost[x][path[x]];
		x = path[x];
		//printf("cc[%d]=%d \n", i, cc[i]);
	}
	
	sort(cc+1, cc+n);
	
	if(k < n) {
		for(i = 1; i <= k; i++)
			dist[n] -= 2 * cc[n-i];	
	}
	
	printf("%d", dist[n]);
	return 0;
}
