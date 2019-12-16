#include <bits/stdc++.h>
using namespace std;

long double a, sum = 0.0; 

int main()
{
	while(scanf("%llf", &a) != EOF){
		sum += a*1000000;
	}

	printf("%.5llf", sum / 1000000);	
		
	return 0;
}
