#include <bits/stdc++.h>
using namespace std;

int s;
int a[1002];
int f[1002];

int sumprime()
{
	for(int i = 2; i <=s; i++) {
		for(int k = 2; k*k <= i; k++) {
			if(i % k == 0) {
				a[i] += k;
				if(i/k != k)
					a[i] += i/k;
			}		
		}
		a[i] += 1;
	}
}

int main()
{
	int i, v;
	scanf("%d", &s);
	
	sumprime();
	
	for(i = 1; i <=s; i++)
		for(v = s; v >= i; v--) {
			f[v] = max(f[v], f[v-i] + a[i]);
		}
	
	printf("%d", f[s]);
	
	return 0;
}
