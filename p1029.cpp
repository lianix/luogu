#include <bits/stdc++.h>
using namespace std;

int x, y;
int cnt;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int p, q, r;
	scanf("%d %d", &x, &y);
	for(p = x; p <= y; p+=x)
		for(q = x; q <= y; q+=x)
	{
		if(y%p != 0)
			continue;
		if(y%q != 0)
			continue;
		r = gcd(p, q);	
		//printf("%d %d-> %d\n", p, q, r);
		if(r != x)
			continue;
		if(p/r*q != y)
			continue;
		cnt++;
	}
	
	printf("%d", cnt);
	return 0;
} 
