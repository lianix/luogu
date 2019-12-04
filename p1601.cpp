#include <bits/stdc++.h>
using namespace std;

int a[506], b[506], sum[506];
char ac[506], bc[506];
//int lena, lenb, lensum;
// 使用a[0] b[0] sum[0] 表示长度 
int add(int a[], int b[], int sum[])
{
	int i = 1, x = 0;
	while(i <= a[0] || i <= b[0]) {
		sum[i] = a[i] + b[i] + x;
		x = sum[i]/10;
		sum[i] = sum[i] % 10;
		i++;
	}
	
	while(x) {
		sum[i] = x % 10;
		x /= 10;
		i++;
	}
	
	sum[0] = i - 1;
}

int main()
{
	scanf("%s", ac);
	scanf("%s", bc);
	
	a[0] =strlen(ac);
	int i, k;
	for(i = 0; i < a[0]; i++)
	{
		a[a[0]-i] = ac[i] - '0';
	}
	
	b[0] = strlen(bc);
	for(i = 0; i < b[0]; i++)
	{
		b[b[0]-i] = bc[i] - '0';
	}
	
	add(a, b, sum);
	
	for(i = sum[0]; i >= 1; i--)
		printf("%d", sum[i]);
		
	return 0;
}
