#include<bits/stdc++.h> 
using namespace std;

const int MAXN = 1000006;

int n, m; 
int st[MAXN][25];

int query(int left, int right)
{
    int k = log2(right - left + 1);
	 
    return min(st[left][k], st[right - (1 << k) + 1][k]);
}

int main()
{
	int i, j;
	
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &st[i][0]);
    
	for(j = 1; j <= 21; j++) {
		for(i = 1; i+(1<<j)-1 <= n; i++) {
        	st[i][j] = min(st[i][j-1],
						   st[i + (1 << (j-1))][j-1]);
		}
	}
        
    for(i = 1; i <= n-m+1 ; i++) {
        printf("%d\n", query(i, i+m-1));
	}
	
    return 0;
}
