#include <bits/stdc++.h>
using namespace std;

int a, b;
int len, cnt;

int main(){
	
	scanf("%1d", &a);
	while(scanf("%1d", &b) != EOF) {
		if(b != a)
			cnt++;
		a = b;
	}
	
	if(a != 1)
		cnt++;
			
	printf("%d", cnt);

	return 0;
}
