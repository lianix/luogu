#include <bits/stdc++.h>
using namespace std;

long long n, fn[50], d;
long long mask = (1 << 31);
int main()
{
	int i;
	
	scanf("%d", &n);
	
	fn[0] = 0;
	fn[1] = 1;
	fn[2] = 1;
		
	for(int i = 3; i <= n; i++) {
		fn[i] = fn[i - 1] + fn[i - 2];
		fn[i] %= mask;
	}

	d = fn[n];
	printf("%lld=", d);
	i = 2;
	int first = 1;
	while(i <= d) {
		if(d%i == 0) {
			if(first == 1)  {
				printf("%d", i);
				first = 0;
			}
				
			else
				printf("*%d", i);
				
			d = d/i;
		} else
			i++;	
	}
	
	return 0;
}
