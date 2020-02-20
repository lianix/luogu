#include <bits/stdc++.h>
using namespace std;

int code[65];
unsigned long long k, middle;
int n;

int main()
{
	scanf("%d %llu", &n, &k);
	int bitn = n;
	int i;
	
	for(i = 1; i <= n; i++) {
		middle = (1ull << (bitn-1)) - 1;
		if(k <= middle) {
			code[i] = 0;
		} else {
			code[i] = 1;
			k = middle - (k - middle - 1);
		//	printf("k = %d\n", k);
		}
		bitn--;
	}
	
	for(i = 1; i <= n; i++) {
		printf("%d", code[i]);
	}
	
	return 0;
}

