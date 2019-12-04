#include <bits/stdc++.h>
using namespace std;

int n, m;
int prime[1000008];

void findprime()
{
	prime[0] = 1;
	prime[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	{
		if(prime[i] == 0) {
			// is prime
			for(int j = i+i; j <= 1000000; j = j+i)
			{
				prime[j] = 1;
			}
		} else {
			continue;
		}
	}	
}

int main()
{
	int a, b, cnt;
	findprime();
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		if(b > m || a > m || a <= 0 || b <= 0) {
			printf("Crossing the line\n");
			continue;
		}
		cnt = 0;
		for(int k = a; k <=b; k++) {
			if(prime[k] == 0)
				cnt++;		
		}
		printf("%d\n", cnt);			
	}
	
	return 0;
}
