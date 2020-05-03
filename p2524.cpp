#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
char a[1006];
int b[10];
int ans;

int main()
{
	scanf("%d %s",&n, a);
	b[0] = 1;
	for(int i = 1; i < n; i++) {
		b[i] = b[i-1]*i;
	}

	
	for(int i = 0; i < n; i++) {
		int num = 0;
		for(int j = i + 1; j <n; j++) {
			if(a[j] < a[i])
				num++;
		}
		ans += num * b[n - i - 1];
	}

	printf("%d", ans);
	return 0;
}
