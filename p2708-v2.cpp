#include <bits/stdc++.h>
using namespace std;

char str[10006];
int len, cnt;

int main(){
	scanf("%s",str);
	len = strlen(str);
	for(int i = 1; i < len; i++){ 
    	if(str[i]!=str[i - 1]) {
			cnt++;
		}
	}
  	if(str[len-1] == '0'){
	  	cnt++;
	}
	
	printf("%d", cnt);

	return 0;
}

