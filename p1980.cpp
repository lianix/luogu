#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
int x;
int ans = 0;
int main()
{
	scanf("%d %d", &n, &x);
	
	for (int i = 1; i <= n; i++) {
		m = i;
		while(1) {
			if (m%10 == x)
				ans++;
			m= m/10;
			if (m == 0)
				break;
		}
	}
	printf("%d", ans);
	return 0;
}

