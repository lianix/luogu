#include <bits/stdc++.h>
using namespace std;

char ac[2008], bc[2008];
int a[2008], b[2008], ans[4000008];
// 使用a[0] b[0] ans[0] 表示长度 

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
    for(int i = ans[0]; i >=1; i--)
        printf("%d", ans[i]);
}

void mult(int a[], int b[], int ans[])
{
	int i, j, len;
	
	for(i = 1; i <= a[0]; i++) { 
		for(j = 1; j <= b[0]; j++) { 
			ans[i+j-1] += a[i] * b[j];
		}
	}
	
	len = a[0] + b[0];
	for(i = 1; i < len; i++) {
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10; 
	}
	
	while(ans[i] == 0 && i > 1)
		i--;
		
	ans[0] = i;	
}

int main()
{
	scanf("%s", ac);
	scanf("%s", bc);

	convert(ac, a);
	convert(bc, b);
	mult(a, b, ans);
	print(ans);	
		
	return 0;
}

