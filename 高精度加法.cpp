#include <bits/stdc++.h>
using namespace std;

const int MAXN = 506;
int a[MAXN], b[MAXN], sum[MAXN];
char ac[MAXN], bc[MAXN];

//int lena, lenb, lensum;
// 使用a[0] b[0] sum[0] 表示长度 

void convert(char ca[], int a[])
{
    int len = strlen(ca);
	for(int i = 1; i <= len; i++)
	{
		a[i] = ca[len - i] - '0';
	}
	a[0] = len;
}

void print(int ans[])
{
    for(int i = ans[0]; i >= 1; i--)
        printf("%d", ans[i]);
}

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
	
	convert(ac, a);
	convert(bc, b);
	
	add(a, b, sum);
	
    print(sum);
		
	return 0;
}
