#include <bits/stdc++.h>
using namespace std;

const int MAXN=1002;
int a[MAXN], b[MAXN], c[101][MAXN];
int f[MAXN]; 
int n, m, t;

int main() 
{
	int i, j, k, idx;
	
	scanf("%d %d",&m,&n);
	for(i = 1; i <= n; i++) {
		int cc;
		scanf(" %d %d %d", &a[i], &b[i], &cc);
		c[cc][0]++;
		c[cc][c[cc][0]] = i;
		t = max(t, cc);
	}
	
	for(i = 1; i <= t; i++) {
		for(j = m; j >= 0; j--) {
			for(k = 1;k <=c[i][0]; k++) {
				idx = c[i][k];
				if(j >= a[idx])
					f[j]=max(f[j], f[j-a[idx]] + b[idx]);
			}
		}
	}
	
	printf("%d", f[m]);
}
