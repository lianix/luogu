#include <bits/stdc++.h>
using namespace std;

char a[260];
char b[260];
int len, k;
int flag = false;
int bidx;

void dfs(int start, int m)
{
	char minc = '9' + 1;
	int idx, i;
	
	if(m == 0)
		return;

	for(i = start; i <= len - m; i++) {
		if(a[i] < minc) {
			minc = a[i];
			idx = i;
		}
	}
	
	
	b[bidx++] = a[idx];
	
	dfs(idx + 1, m -1);
}
	
int main()
{
	scanf("%s", a);
	scanf("%d", &k);
	
	len = strlen(a);
	
	dfs(0, len - k);
	
	int printflag = 0;
	
	for(int i = 0; i < bidx; i++) {
		if(printflag)
			printf("%c", b[i]);
		else {
			if(b[i] == '0')
				continue;
			else {
				printf("%c", b[i]);
				printflag = 1;
			}
		}
	}
	
	if(printflag == 0)
		printf("0");
	
	return 0;
}
