#include <bits/stdc++.h>
using namespace std;

long a[101];
int n, i;

int main()
{
	for(i=0; i<100;i++)
	{
		scanf("%ld", &a[i]);
		if (a[i]==0)
			break;
	}
	i--;
	while(i>=0){
		printf("%ld ", a[i--]);
	}
	
	return 0;
}
