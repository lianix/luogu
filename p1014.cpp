#include <cstdio>
using namespace std;

int m,n; //m–– n¡–
int k,N; 

int main()
{
	scanf("%d", &N);
	m = n = 1;
	int flag = 1;
	N--;
	while(N--) {
		if(flag == 1) {
			n++;
			flag = 2;
		} else if(flag == 2) {
			m++;
			n--;
			if(n==1)
				flag = 3;
		} else if(flag == 3) {
			m++;
			flag = 4;
		} else if(flag == 4) {
			n++;
			m--;
			if(m==1)
				flag =1;
		} 
	
		//printf("%d--%d/%d\n", N, m, n);
	}
	
	printf("%d/%d", m, n);
	return 0;
}

