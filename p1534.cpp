#include <cstdio>

using namespace std;

int a, b;
int n, total, gaoxing; 

int main()
{
	scanf("%d", &n);
	
	for(int i = 1; i <=n; i++) {
		scanf("%d %d", &a, &b);
		gaoxing += (a+b) - 8;
		total += gaoxing;
	}
	
	printf("%d\n", total);
	
	return 0;
}

