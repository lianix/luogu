#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
char a[1006];

int main()
{
	scanf("%d %s",&n, a);
	int len = strlen(a);
	len--;
	 
	printf("%d*%d^%d",
			a[0] - '0', n, len);
	for(int i = 1; i <= len; i++) {
		if(a[i] == '0')
			continue;

		printf("+%d*%d^%d",
			a[i] - '0', n, len - i);
	}

	return 0;
}
