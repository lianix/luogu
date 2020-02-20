#include <bits/stdc++.h>
using namespace std;

int t, m;
int a[10002], v[10002];
int f[100002]; 

int main()
{
	scanf("%d %d", &t, &m);
	for(int i=1; i <=m; i++) {
		scanf("%d %d", &a[i], &v[i]);	
	}	
	
	for(int i = 1; i <= m; i++)
		for(int j = 0; j <= t; j++) {
			if(j >= a[i])
				f[j] = max(f[j], f[j-a[i]] + v[i]);
	}
		
	printf("%d", f[t]);
	
	return 0;
} 
