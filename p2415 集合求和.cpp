#include <bits/stdc++.h>
using namespace std;

long long ans, n;
int a;

int main()
{
	n = 1; //��������, 1: �ռ��� 
	while(scanf("%d", &a) != EOF) {
		ans = ans + ans + n * a;
		n *= 2; 
	}
	
	printf("%lld", ans);
		
	return 0;
} 
