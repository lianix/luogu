#include <bits/stdc++.h>
using namespace std;

int a[8];
int w[8] = {0, 1, 2, 3, 5, 10, 20};
int f[2002], ans;

int main()
{
	int i, w1, ww, w3;
	
	for(i = 1; i <= 6; i++)
		scanf("%d", &a[i]);
	
	for(i = 1; i <= 6; i++) {
		for(ww = 1000; ww >= 1; ww--) {
			if(f[ww] == 0)
				continue;
			for(int k = 1; k <= a[i]; k++) {
				w1 = k * w[i];
				f[ww + w1] = 1;
			}
		}
		
		for(int k = 1; k <= a[i]; k++) {
			w1 = k * w[i];
			f[w1] = 1;
		}
	}
			
	for(i = 1; i <= 1000; i++)
		if(f[i] != 0)
			ans++;
			
	printf("Total=%d\n", ans);
	
	return 0;
}
