#include <cstdio>
#include <cmath>
using namespace std;

int a, b ,x;
int an, bn, tmp,i;

int isPrime(int n)
{
	int m = sqrt(n);
	for (int i = 2; i <=m; i++) {
		if(n%i == 0)
			return 0;
	}
	
	return 1;
}

void f(int k)
{
	if(k==1)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			x= d1;
			if (x < a)
				continue;
			if (x>b)
				break;
			if(isPrime(x))
				printf("%d\n",x);
		}
	}
	
	else if(k==2)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			x= d1*10 + d1;
			if (x < a)
				continue;
			if (x>b)
				return;
			if(isPrime(x))
				printf("%d\n",x);
		}
	}
	
	
	else if(k==3)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				x= d1*100+ d2*10 + d1;
				if (x < a)
					continue;
				if (x>b)
					return;
				if(isPrime(x))
					printf("%d\n",x);
			}
		}
	}
	
	else if(k==4)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				x= d1*1000+ d2*100 + d2*10 + d1;
				if (x < a)
					continue;
				if (x>b)
					return;
				if(isPrime(x))
					printf("%d\n",x);
			}
		}
	}
	
	else if(k==5)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				for(int d3 = 0; d3 <=9; d3++)  {
					x= d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
					if (x < a)
						continue;
					if (x>b)
						return;
					if(isPrime(x))
						printf("%d\n",x);
				}
			}
		}
	}
	
	else if(k==6)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				for(int d3 = 0; d3 <=9; d3++)  {
					x= d1*100000 + d2*10000 + d3*1000 + d3*100 + d2*10 + d1;
					if (x < a)
						continue;
					if (x>b)
						return;
					if(isPrime(x))
						printf("%d\n",x);
				}
			}
		}
	}
	
	else if(k==7)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				for(int d3 = 0; d3 <=9; d3++)  {
					for(int d4 = 0; d4 <=9; d4++)  {
						x= d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
						if (x < a)
							continue;
						if (x>b)
							return;
						if(isPrime(x))
							printf("%d\n",x);
					}
				}
			}
		}
	}
	
	else if(k==8)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				for(int d3 = 0; d3 <=9; d3++)  {
					for(int d4 = 0; d4 <=9; d4++)  {
						x= d1*10000000 + d2*1000000 + d3*100000 + d4*10000 + d4*1000 + d3*100 + d2*10 + d1;
						if (x < a)
							continue;
						if (x>b)
							return;
						if(isPrime(x))
							printf("%d\n",x);
					}
				}
			}
		}
	}
	
	else if(k==9)
	{
		for(int d1 = 1; d1 <=9; d1+=2) {
			for(int d2 = 0; d2 <=9; d2++)  {
				for(int d3 = 0; d3 <=9; d3++)  {
					for(int d4 = 0; d4 <=9; d4++)  {
						for(int d5 = 0; d5 <=9; d5++) {
							x= d1*100000000 + d2*10000000 + d3*1000000 + d4*100000 + d5*10000 + 
							    d4*1000 + d3*100 + d2*10 + d1;
							if (x < a)
								continue;
							if (x>b)
								return;
							if(isPrime(x))
								printf("%d\n",x);
						}
					}
				}
			}
		}
	}
	
}

int main()
{
	scanf("%d %d", &a, &b);
	tmp =a;
	i = 0;
	while(tmp){
		tmp = tmp /10;
		i++;
	}
	an = i;
	
	tmp =b;
	i = 0;
	while(tmp){
		i++;
		tmp = tmp /10;
	}
	bn = i;
	
	for(i = an; i <=bn; i++)
		f(i);
		
	return 0;	
}
