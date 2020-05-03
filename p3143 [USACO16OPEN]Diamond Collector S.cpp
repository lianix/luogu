#include<bits/stdc++.h>
using namespace std;

const int MAXN=500002;

int n,k;
int a[MAXN], f[MAXN];
int ans;

int main()
{
	int i;
	
	scanf("%d %d", &n, &k);
    
	for(i = 1; i <= n; i++) { 
		scanf("%d", &a[i]);
	}    
	
	sort(a + 1, a + n + 1);
	
    for(i = 1; i <= n; i++)
		f[i] = upper_bound(a+1, a+1+n, a[i]+k) - a - i;
		
    for(i = n; i >= 1; i--) {
    	ans = max(ans, f[i] + f[i+f[i]]);
		f[i] = max(f[i], f[i+1]);	
	} 
	
	printf("%d\n", ans);
    return 0;
}
