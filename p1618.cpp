#include <cstdio>
using namespace std;

int d[10];
int a, b,c;

int main()
{
	int m, n;
	scanf("%d %d %d", &a, &b, &c);
	for(int i = 123; i < 999/c; i++) {
		m = b*i;
		n = c*i;
		check(i, b*i, c*i);
	}
	
}
