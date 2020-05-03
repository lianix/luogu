#include <bits/stdc++.h>
using namespace std;

long long ans, n;
int a;

int main()
{
	n = 1; //集合数量, 1: 空集合 
	while(scanf("%d", &a) != EOF) {
		ans = ans + ans + n * a;
		n *= 2; 
	}
	
	printf("%lld", ans);
		
	return 0;
} 
