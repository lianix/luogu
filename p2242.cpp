#include <bits/stdc++.h>
using namespace std;

long long a[15008];
long long b[15008];
int  n, m;
long long dist;

int main()
{
	int i;
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i] - a[i - 1];
		dist +=b[i];
	}
	
	dist -= b[1];
	
	sort(b+2, b+n+1);
	
	for(i = 0; i < m - 1; i++)
		dist -= b[n-i];
		
	printf("%lld ", dist+m);
	
	return 0;
}
