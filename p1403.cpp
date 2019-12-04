#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

int main()
{
	int i;
	scanf("%d", &n);
	for(i = 1; i <=n; i++)
		ans += n / i;

	printf("%d", ans);
	return 0;
}
