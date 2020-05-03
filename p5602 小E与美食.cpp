#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+2;
int a[MAXN];
int n;
long double sum, ans, tmp;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a+1, a+n+1);
	
	for(int i = n; i >= 1; i--) {
		sum += a[i];
		tmp = sum * sum / (n - i + 1);
		if(tmp < ans)
			break;
			
		ans = tmp;
	}

	printf("%.8Lf\n", ans);
printf("%d-- %d --%d", sizeof(long long), sizeof(long double), sizeof(double));
	return 0;
}
