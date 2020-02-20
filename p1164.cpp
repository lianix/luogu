#include <cstdio>
#include <cstdlib>
using namespace std;

int price[102];
int n, m, cnt;
int f[10002];

int main()
{
	int i, p;
	
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%d", &price[i]);
	}

	f[0] = 1;
	for(i = 1; i <= n; i++) {
		for(p = m; p >= price[i]; p--) {
			f[p] += f[p-price[i]];
		}
	}
	
	printf("%d", f[m]);
	
	return 0;
}
