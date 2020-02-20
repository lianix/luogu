#include <bits/stdc++.h>
using namespace std;

int n;

void cifang(int m)
{
	int k[32], idx = 0;
			
	while(m) {
		k[idx] = m % 2;
		m = m / 2;
		idx++;
	}
	
	for(int i = idx - 1; i >= 0; i--) {
		if(k[i] == 0)
			continue;
			
		if(i != idx -1)
			printf("+");

		if(i == 0) {
			printf("2(0)");
			continue;
		}
		
		if(i == 1) {
			printf("2");
			continue;
		}
		
		printf("2(");
		cifang(i);
		printf(")");
	}
	
}

int main()
{
	scanf("%d", &n);
	cifang(n);
	
	return 0;
}
