#include <cstdio>
#include <cstring>
using namespace std;

int d[10];
int a, b,c;
int flag = 0;

int check1(int n)
{
	int m;
	while(n){
		m = n%10;
		if(m == 0)
			return 0;
		d[m]++;
	//	printf("%d - d[%d]=%d\n", n, m, d[m]);
		if(d[m] !=1)
			return 0;
		n/=10;	
	}
	
	return 1;
}

int check3(int x, int y, int z)
{
	int j;
	memset(d, 0, sizeof(d));
	
//	printf("%d  %d  %d\n", x, y, z);
	
    if(check1(x) && check1(y) && check1(z)) {
    	printf("%d %d %d\n", x, y, z);
    	flag = 1;
	}	
}

int main()
{
	scanf("%d %d %d", &a, &b, &c);
	for(int i = 123; i < 999*a/c; i++) {
		check3(i, i*b/a, c*i/a);
	}
	
	if(flag == 0)
		printf("No!!!");
}
