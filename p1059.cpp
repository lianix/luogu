#include <bits/stdc++.h>
using namespace std;

int a[1008];
int n, m;

int main()
{
	int k;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &k);
		if(a[k] == 0) {
			a[k] = 1;
			m++;
		}
	}
	
	printf("%d\n", m);
	for(int i = 0; i <= 1000; i++) {
		if(a[i] == 1)
			printf("%d ", i);
	}
	
	return 0;
}
