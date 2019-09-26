#include <bits/stdc++.h>

using namespace std;

int a[110];
int n;

int main()
{
	int flag;
	scanf("%d", &n);
	for(int i =0; i<=n; i++){
		scanf("%d", &a[i]);
	}
	
	flag = 0;
	for(int i =0; i <n; i++){
		if(a[i] == 0)
			continue;
		
		if(flag == 0) {
			flag = 1;
			
			if (a[i] == -1)
				printf("-");
			else if (a[i] == 1)
				;
			else
				printf("%d", a[i]);
		} else {
			if(a[i] > 1)
				printf("+%d", a[i]);
			else if (a[i] == 1){
				printf("+");
			}else if (a[i] == -1){
				printf("-");
			}
			else
				printf("%d", a[i]);
		}
					
		if(i == n-1) {
			printf("x");
		} else {
			printf("x^%d", n-i);
		}
	}
	
	if(flag == 0) {
		printf("%d", a[n]);
	} else {
		if (a[n] > 0 ){ 
			printf("+%d", a[n]);
		} else if (a[n] < 0 ) {
			printf("%d", a[n]);
		}
	} 
		
	return 0;
}
