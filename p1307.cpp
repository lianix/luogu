#include <cstdio>
using namespace std;

int n, m, k;
int flag;

int main()
{
	scanf("%d", &n);
	if (n < 0) {
		n *= (-1);
		flag = -1;
	} else {
		flag = 1;
	}
	
	while(n){
		k = n%10;
		m = m * 10 + k;
		n /= 10;
	}	
	
	if(flag == -1)
		printf("-%d", m);
	else
	 	printf("%d", m);
	 	
	return 0;
}
