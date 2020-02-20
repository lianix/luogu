#include<bits/stdc++.h>
using namespace std;

int n, d[10], used[10];

void dfs(int idx)
{
	int i;
	if(idx == n + 1) {
		for(i = 1; i <= n; i++) {
			printf("%5d", d[i]);
		}
		printf("\n");
		return;
	}
	
	for(i = 1; i <= n; i++) {
		if(used[i]) 
			continue;
		d[idx] = i;
		used[i] = 1;
		dfs(idx + 1);
		used[i] = 0;
	}
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
