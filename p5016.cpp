#include <bits/stdc++.h>
using namespace std;

long long bing[100008];
long long n, m, p1, s1, s2, p2;
long long dragon, tiger;
long long min;

int main()
{
	int i;
	
	//freopen("longhu.in", "r", stdin);
//	freopen("longhu.out", "w", stdout);
	
	scanf("%d", &n);
	for(i = 1; i <=n; i++) {
		scanf("%d", &bing[i]);	
	}
	
	scanf("%d %d %d %d", &m, &p1, &s1, &s2);
	
	bing[p1] += s1;
		
	for(i = 1; i < m; i++) {
		dragon += bing[i] * (m - i);
	}
	
	for(i = m + 1; i <= n; i++) {
		tiger += bing[i] * (i - m);
	}
	
	if(dragon > tiger) {
		long long min = dragon - tiger, c1;
		p2 = m;
		for(i = m + 1; i <= n; i++) {
			c1 = llabs(dragon - tiger - s2 * (i - m));
			if(c1 < min) {
				min = c1;
				p2 = i;
			}
		}
		
	} else {
		long long min = tiger - dragon , c1;
		p2 = m;
		for(i = 1; i < m; i++) {
			c1 = llabs(tiger - dragon - s2 * (m-i));
			if(c1 < min) {
				min = c1;
				p2 = i;
			}
		}	
	}

	printf("%d", p2);
	return 0;
}
