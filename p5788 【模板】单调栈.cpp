#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e6 + 1;
int  n, top;
int a[MAXN], b[MAXN], f[MAXN];

int main()
{
    scanf("%d", &n);
    
    top = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while(top && a[i] > a[f[top]]) {
        	b[f[top]] = i;
        	top--;
		}
		top++;
		f[top] = i;
    }
    while(top) {
    	b[f[top]] = 0;
    	top--;
	}
    	
    for(int i= 1; i <= n; i++) {
    	printf("%d ", b[i]);
	}
	
    return 0;
}

