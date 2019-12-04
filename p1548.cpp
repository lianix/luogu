#include <bits/stdc++.h>
using namespace std;

int m, n;
int s, t;

int main()
{
	int a1, a2, b1, b2;
	
	scanf("%d %d", &n, &m);
	for(a1 = 0; a1<= n; a1++)
		for(a2 = a1 + 1; a2 <= n; a2++)
			for(b1 = 0; b1 <= m; b1++)
				for(b2 = b1 + 1; b2 <= m; b2++)	{
					if(a2 - a1 == b2 - b1)
						s++;
					else
						t++;
				 }
	
	printf("%d %d", s, t);
	return 0;
}
