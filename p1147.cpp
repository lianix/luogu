#include<bits/stdc++.h>
using namespace std;

int m;
int main()
{
	scanf("%d", &m);
	int i, j, sum;
	for(int i=1;i<= m/2;i++) {
		sum=0;
		for(j= i; j < m; j++) {
			sum += j;
			if(sum >= m)break;
		}
		if(sum == m)
			printf("%d %d\n", i, j); 
	}
	
	return 0;
}
