#include <bits/stdc++.h>
using namespace std;

int n;
int a[100], sum[100];

void add(int sum[], int a[])
{
	int x = 0, len, i;
	
	if(a[0] > sum[0])
		len = a[0];
	else
		len = sum[0];
	
	for(i = 1; i <= len;  i++) {
		sum[i] += a[i] + x;
		x = sum[i] / 10;
		sum[i] = sum[i] % 10;
	}
	
	if(x > 0) {
		sum[i] = x;
		sum[0] = i;
	} else
		sum[0] = i - 1;
}


void multiply(int a[], int n)
{
	int x = 0, len, i;
	
	for(i = 1; i <= a[0];  i++) {
		a[i] = a[i] * n + x;
		x = a[i] / 10;
		a[i] = a[i] % 10;
	}
	
	while(x > 0) {
		a[i] = x % 10;
		x = x / 10;
		i++;
	}
	
	a[0] = i - 1;
}

int main()
{
	scanf("%d", &n);
	
	a[1] = 1;
	a[0] = 1;
	for(int i=1; i <=n; i++) {
		multiply(a, i);
		add(sum, a);
	}	
		
	for(int i = sum[0]; i>=1; i--)
		printf("%d", sum[i]);
	
	return 0;
} 
