#include <bits/stdc++.h>
using namespace std;

char ac[5008];
int a[5008], b, ans[5008];
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

void div(int a[], int b, int ans[])
{
	int i, x = 0;
	
	for(i = a[0]; i >= 1; i--) { 
		x = x * 10 + a[i];
		ans[i] = x / b;
		x = x % b; 
	}
	
	i = a[0];
	while(ans[i] == 0 && i > 1)
		i--;
		
	ans[0] = i;	
}

int main()
{
	scanf("%s", ac);
	scanf("%d", &b);

	convert(ac, a);
	div(a, b, ans);
	print(ans);	
		
	return 0;
}

