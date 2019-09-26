#include <cstdio>
using namespace std;

static int tmp[25][25][25];
long long a, b,c;

int w(long long a, long long b, long long c)
{
	//printf("%lld %lld %lld\n", a, b,c);
	
	if (a <=0 || b <= 0 || c<= 0)
		return 1;
	
	if(a>20 ||  b > 20 || c > 20)
		return w(20, 20, 20);
		
	if (tmp[a][b][c] != 0)
		return tmp[a][b][c];
	
	if (tmp[a][b][c-1] == 0)
		tmp[a][b][c-1] = w(a, b, c-1);
		
	if (tmp[a][b-1][c-1] == 0)
		tmp[a][b-1][c-1] = w(a, b-1, c-1);
		
	if (tmp[a][b-1][c] == 0)
		tmp[a][b-1][c] = w(a, b-1, c);
		
	if (tmp[a-1][b][c] == 0)
		tmp[a-1][b][c] = w(a-1, b, c);
		
	if (tmp[a-1][b-1][c] == 0)
		tmp[a-1][b-1][c] = w(a-1, b-1, c);
		
	if (tmp[a-1][b][c-1] == 0)
		tmp[a-1][b][c-1] = w(a-1, b, c-1);
		
	if (tmp[a-1][b-1][c-1] == 0)
		tmp[a-1][b-1][c-1] = w(a-1, b-1, c-1);
			
	if(a < b && b < c) {
		tmp[a][b][c] = tmp[a][b][c-1] + tmp[a][b-1][c-1] - tmp[a][b-1][c];
	} else {
		tmp[a][b][c] = tmp[a-1][b][c] + tmp[a-1][b-1][c] + tmp[a-1][b][c-1]  -
			tmp[a-1][b-1][c-1];
	}
					
	return tmp[a][b][c];	
}

int main()
{
	while(scanf("%lld %lld %lld", &a, &b, &c)) {
		if(a == -1 && b == -1 && c == -1)
			break;
	
		printf("w(%lld, %lld, %lld) = %d\n",
			a, b, c, w(a,b,c));
	}

	return 0;	
}
