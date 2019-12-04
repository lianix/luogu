#include <bits/stdc++.h>
using namespace std;

int a;
int ans;

bool isprime(int n)
{
	int m = sqrt(n);
	
	if (n==2) return true;
	
 	if(n & 1 == 0)	return false;
	 
	for(int i = 3; i <= m; i+=2) {
		if(n%i == 0)
			return false;
	}
	
	return true;
}

int main()
{
	scanf("%d", &a);

	if (a % 2 == 0) {
		ans = a/2;
		printf("%d", ans);
		return 0;
	}
		
	for(int i = 3; i <= sqrt(a); i += 2) {
		if(a % i != 0)
			continue;
		ans = a/i;
		if(isprime(i) && isprime(ans)) {
			printf("%d", ans);
			return 0;
		}
	}
	
	return 0;
}

