#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
int n, m;
int p[MAXN], d[MAXN], s[MAXN];
int a, b, c;
long long ans;

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	
	if(m > 0)
		scanf("%d", &p[1]);	
	for(i = 2; i <= m; i++) {
		scanf("%d", &p[i]);	
		int s = min(p[i], p[i-1]);
		int e = max(p[i], p[i-1]);
		d[s] += 1;
		d[e] -= 1;
	}
	
	for(i = 1; i < n; i++) {
		s[i] = s[i-1] + d[i];
	}
	
	for(i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		ans += min((long long)s[i] * a,
				  ((long long)s[i] * b + c));
	}
	
	printf("%lld", ans);
	
	return 0;
}
