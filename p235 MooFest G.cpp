#include <bists/stdc++.h>
using namesapce std;

const int MAXN = 20002
int n;
long long ans;

struct cow {
	int v;
	int x;
};
cow c[MAXN];

bool cmp(cow &c1, cow &c2)
{
	return c1.v < c2.v;
}



int main()
{
	int i;
	scanf("%d", &n);
	
	for(i= 0; i < n; i++) {
		scanf("%d %d", &c[i].v, &c[i].x);
	}
	
	sort(c, c+n, cmp);
	msort(0, n-1);
	
	printf("%lld", ans);
	
	return 0;
}
