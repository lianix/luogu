#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+2;

int  a[MAXN];
map<int, int> m;

int n, c;
long long ans;

int main()
{
	int i;
	
	scanf("%d %d", &n, &c);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
		
	for(i=0 ; i<n; i++) {
		ans += m[a[i] - c];
	}
	
	printf("%lld\n", ans); 

	return 0;
}
