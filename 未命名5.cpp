#include <bits/stdc++.h>
using namespace std;

int a[66];
char str[66];
char c[16] = {'0', '1', '2', '3', '4',
				'5', '6', '7', '8', '9', 'A',
				'B', 'C', 'D', 'E', 'F'};
int jinzhi, idx;
long long shu;

int main(){
	scanf("%d", &jinzhi);
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			shu = shu * jinzhi + str[i] - '0';
		} else {
			shu = shu * jinzhi + (str[i] - 'A' + 10);
		}
	}	
	scanf("%d", &jinzhi);
	long long shang;
	do {
		shang = shu / jinzhi;
		a[idx++] = shu % jinzhi;
		shu = shang;
	} while(shang != 0) ;
	
	for(int i = idx -1 ; i >= 0; i--) {
		printf("%c", c[a[i]]);
	}
	 
	return 0;
}
