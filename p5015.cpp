#include <bits/stdc++.h>
using namespace std;

int ans;
char a;

int main()
{
	while((a=getchar())!= '\n') {
		if(a >= 'a' && a <= 'z')
			ans++;
		else if(a >= 'A' && a <= 'Z')
			ans++;
		else if(a >= '0' && a <= '9')
			ans++;	
	}	
	
	printf("%d", ans);
	return 0;
} 
