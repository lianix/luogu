#include <bits/stdc++.h>
using namespace std;

char a[]="0123456789ABCDEFGHIJ";
int yu[64];
int len;
int n, r;

int main()
{
	scanf("%d %d", &n, &r);
	int shang = n;
	int y;
	while(shang) {
		y = shang % r;
		shang = shang/r;
		if(y < 0) {
			y-=r;
			shang++;
		} 
		yu[len++] = y;
	}
	
	printf("%d=", n);
	for(int i = len - 1; i >=0; i--){
		printf("%c", a[yu[i]]);
	}
	printf("(base%d)", r);
	
	return 0;
}
