#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k, total=1, hang = 1;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n*m; i++) {
		total *= k;
	}
	
	for(int i = 1; i <= m; i++) {
		hang *= k;
	}
	hang *= n; 
	
	printf("%d %d  f:%d\n", total, hang, total-hang);
	
	return 0;
}

