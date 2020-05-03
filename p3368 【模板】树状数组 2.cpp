#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+2;
int a[MAXN], c[MAXN];
int n, m;
int opt, x, y, k;

int lowbit(int x)
{
	return x & (-x);
}

void add(int i, int x)
{
	while(i <= n) {
		c[i] += x;
		i += lowbit(i);
	}
}

int sum(int i)
{
    int ans = 0;
    while(i != 0) {
        ans += c[i];
        i -= lowbit(i);
    }
    return ans;
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &opt, &x);
		if(opt == 1) {
			scanf("%d %d", &y, &k);
			add(x, k);
			add(y+1, -k);
		} else {
			printf("%d\n", a[x] + sum(x));
		}
	}
	
	return 0;
}
