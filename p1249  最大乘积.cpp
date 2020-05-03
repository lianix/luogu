#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n;
int ans[MAXN], k[MAXN], ki;

void multiply(int a[], int b)
{
	int x = 0;
	for(int i = 1; i <= a[0]; i++) {
		a[i] = a[i] * b + x;
		x = a[i] / 10;
		a[i] %= 10;
	}
	
	while(x) {
		a[0]++;
		a[a[0]]	= x % 10;
		x = x / 10;
	} 
}

int main()
{
	scanf("%d", &n);

	int ki = 1, m = 2; 
	while(n > 0) {
		k[ki] = m;
		n = n - m;
		if(n <= k[ki])
			break;
		ki++;
		m++;
		
	}
	
	int ti = ki;
	while(n > 0) {
		n--;
		k[ti]++;
		ti--;
		if(ti == 0)
			ti = ki;	
	}
	
	ans[0] = 1;
	ans[1] = 1;
	
	for(int i = 1; i <= ki; i++) {
		printf("%d ", k[i]);
		multiply(ans, k[i]);	
	}
	printf("\n");
	//printf("len: %d\n", ans[0]);

	for(int i = ans[0]; i >= 1; i--)
		printf("%d", ans[i]);
	
	return 0;
}

