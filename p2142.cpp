#include <bits/stdc++.h>
using namespace std;

char ac[10088], bc[10088];
int a[10088], b[10088], ans[10088];
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

int compare(int a[], int b[])
{
    int lena = a[0];
    int lenb = b[0];
    
    if(lena > lenb) return 1;
    if(lenb > lena) return -1;
    for(int i = lena; i >=1; i--)
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    
    return 0; //a==b
}

int sub(int a[], int b[], int ans[])
{
	int i;
	int *big, *little;
	
	if(compare(a, b) >= 0) {
		big = a;
		little = b;	
	} else {
		big = b;
		little = a;
	}
	
	for(i = 1; i <= big[0]; i++) { 
		ans[i] = big[i] - little[i] + ans[i];
		if(ans[i] < 0) {
			ans[i] += 10;
			ans[i + 1] -= 1;
		}
	}
	i = big[0];
	while(ans[i] == 0 && i > 1)
		i--;
	
	if(big == b)
		ans[i] *= -1;
	
	ans[0] = i;
}

int main()
{
	scanf("%s", ac);
	scanf("%s", bc);

	convert(ac, a);
	convert(bc, b);
	sub(a, b, ans);
	print(ans);	
		
	return 0;
}

