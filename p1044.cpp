#include <bits/stdc++.h>
using namespace std;

int n;
long long f[20];

int main()
{
	scanf("%d", &n);	
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			f[i] += f[i-j-1] * f[j];
		}
	}
		
	printf("%d", f[n]);
	
	return 0;
} 
