#include <cstdio>
using namespace std;

int day, n ;
long long ans = 0;
int main()
{
	scanf("%d %d", &day, &n);
	
	for (int i = 1; i <=n; i++)
	{
		if (day != 6 && day != 7) {
			ans += 250;
		}
	
		day++;
		if (day == 8)
			day = 1;
	}
	
	printf("%lld\n", ans);
	return 0;
}

