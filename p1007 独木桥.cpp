#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5006;
int n, l, ansmin = 0, ansmax = 0;

int main()
{
	int i, a, tmp;
	scanf("%d %d", &l, &n);
	l+=1;
	for(i =1; i <= n; i++) {
		scanf("%d", &a);
		tmp = min(a, l-a);
		ansmin = max(ansmin, tmp);
		ansmax = max(ansmax, l-tmp);
	}
	
	printf("%d %d", ansmin, ansmax);
	
	return 0;
}
