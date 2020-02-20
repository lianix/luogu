#include <bits/stdc++.h>
using namespace std;

int a[26];
int n, r;

void dfs(int start, int num)
{
	int i;
	if(num == r) {
		for(i = 0; i < r; i++) {
			printf("%3d", a[i]);
		}
        printf("\n"); 
		return ;   
	}
	      
	for(i = start; i <= n; i++) {
		a[num] = i;
		dfs(i + 1, num + 1);
	}	
}

int main()
{
    scanf("%d %d", &n, &r );
    dfs(1, 0);
    
    return 0;
}
