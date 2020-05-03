#include <bits/stdc++.h>
using namespace std;

const int MAXN = 106;
 
int n, a[MAXN];
int fl[MAXN], fr[MAXN], ans;

int main()
{
	int i, k;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
			
	for(i = 1; i <= n; i++) { 
		for(k = 1; k < i; k++) {
			if(a[i] > a[k])
				fl[i] = max(fl[i], fl[k]);
		}
		
		fl[i]++;
	}

	for(i = n; i >= 1; i--) { 
		for(k = n; k > i; k--) {
			if(a[i] > a[k])
				fr[i] = max(fr[i], fr[k]);
		}
		fr[i]++;
	}
	
	for(i = 1; i <= n; i++) {
		ans = max(ans, fl[i] + fr[i] - 1);
	}
	
    printf("%d\n", n - ans);
}
