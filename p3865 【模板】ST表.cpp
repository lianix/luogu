#include<bits/stdc++.h> 
using namespace std;

const int MAXN=1e5+6;

int st[MAXN][30];
int n, m;

int query(int left, int right)
{
    int k = log2(right - left + 1);
	 
    return max(st[left][k], st[right - (1 << k) + 1][k]);
}

int main()
{
	int i, j, maxj;
	
	scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++) {
    	scanf("%d", &st[i][0]);
	}
	
    for(j = 1; j <= 21; j++)
        for(i = 1; i+(1<<j)-1 <= n; i++) {
        	st[i][j] = max(st[i][j-1],
						   st[i + (1 << (j-1))][j-1]);
		}
		
    for(i = 1; i <= m; i++) {
    	int lft, rgt;
        scanf("%d %d", &lft, &rgt);
        printf("%d\n", query(lft, rgt));
    }
    
    return 0;
}
