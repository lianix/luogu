
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a1, b1, a2, b2, a3, b3;
	int pen, p1, p2, p3, ans;
	scanf("%d", &pen);
	scanf("%d %d", &a1, &b1);
	scanf("%d %d", &a2, &b2);
	scanf("%d %d", &a3, &b3);
	
	p1 = ceil(1.0 * pen / a1) * b1;
	p2 = ceil(1.0 * pen / a2) * b2;
	p3 = ceil(1.0 * pen / a3) * b3;
	
	ans = min(p1, p2);
	ans = min(ans, p3);
	
	printf("%d\n", ans);
	
	return 0
}
