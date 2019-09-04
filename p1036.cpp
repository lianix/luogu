#include <cstdio>
#include <cmath>
using namespace std;

int n, k, x[22];
int cnt = 0;
int sum = 0;

int isPrime(int a)
{
	int m = sqrt(a);
	
	if(a == 1)
		return 0;
		
	if(a==2 || a==3)
		return 1;
		
	for (int i = 2; i <=m; i++) {
		if(a%i == 0)
			return 0;
	}
	
	return 1;
}


int find(int start, int m)
{
	if(m == 0) {
		if(isPrime(sum)) {
		//	printf("is prime\n");
			cnt++;
		}	
		return 0;
	}
	
	for(int i = start; i<=n-m+1; i++){
		sum +=x[i];
		//printf("sum=%d +  x[%d]=%d\n", sum, i, x[i]);
		find(i+1, m-1);
		sum -=x[i];
		//printf("sum=%d  - x[%d]=%d\n", sum, i, x[i]);
	}
	
	return 1;
}


int main()
{
	scanf("%d %d", &n, &k);
	for(int i =1; i <=n; i++)
	{
		scanf("%d", &x[i]);
	}
	
	find(1, k);

	printf("%d", cnt);
	return 0;	
}
