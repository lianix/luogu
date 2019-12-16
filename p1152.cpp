#include <bits/stdc++.h>
using namespace std;

int a[1010], b[1010], n;

int main()
{
	scanf("%d", &n);
	
	int i;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int c;
	for(i = 0; i < n-1; i++) {
		c = abs(a[i] - a[i+1]);
		if(c <= 0 || c>=n || b[c]!= 0) {
			printf("Not jolly");
			return 0;
		}
		b[c]++;
	}
	
	printf("Jolly");
	return 0;
}
