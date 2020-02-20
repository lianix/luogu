#include <bits/stdc++.h>
using namespace std;

int n, a[202], suma[202];
int ffmin[202][202], ffmax[202][202], ans;
 
int main()
{
	int i, k, len;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[n+i] = a[i];
	}
		
	for(i = 1; i <= 2*n; i++){
		suma[i] = suma[i - 1] + a[i];
	}
	
	for(len = 1; len < n; len++) // 长度 
		for(i = 1; i+len < 2*n; i++) { // 起点 
			int ends = i + len; //终点 
			ffmin[i][ends] = 0x47474747;
			for(k = i; k < ends; k++) { // 中间点
				ffmin[i][ends] = min(ffmin[i][ends],
					ffmin[i][k] + ffmin[k+1][ends] + 
					suma[ends] - suma[i-1]);
				ffmax[i][ends] = max(ffmax[i][ends],
					ffmax[i][k] + ffmax[k+1][ends] + 
					suma[ends] - suma[i-1]);
			}
		}
		
	ans = 0x47474747;
	for(i = 1; i <= n; i++)
		ans = min(ans, ffmin[i][i + n - 1]);
	printf("%d\n", ans);
	
	ans = 0;
	for(i = 1; i <= n; i++)
		ans=max(ans,ffmax[i][i+n-1]);
    printf("%d\n", ans);
}
