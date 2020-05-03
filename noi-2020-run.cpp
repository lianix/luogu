#include <bits/stdc++.h>
using namespace std;

int n, p;

int f[100006];
int ans;

int main()
{
	scanf("%d %d", &n, &p);
 
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			f[j] += f[j - i];
			f[j] %= p;
		}
	}	

	printf("%d", f[n]);
} 
