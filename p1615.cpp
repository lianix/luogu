#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n = 0, n1, n2;
	int h,m,s;
	
	scanf("%d:%d:%d", &h, &m, &s); 
	n1 = (h*60+m)*60 + s;
	
	scanf("%d:%d:%d", &h, &m, &s); 
	n2 = (h*60+m)*60 + s;
	
	scanf("%lld", &n); 
	
	if(n2 > n1)
		n = (n2-n1) * n;
	
	printf("%lld", n);
	
	return 0;
 } 
