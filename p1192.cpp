#include <bits/stdc++.h>
using namespace std;

int n, k;
int s[100008];

int main()
{
	scanf("%d %d", &n, &k);
	s[1] = 1;
	s[0] = 1;
	
	int i, step, last;
	for(i = 2; i <= n; i++) {
		last = i - k;
		if (last < 0)
			last = 0;
		
		for(step = i - 1; step >= last; step--) {
			s[i] += s[step];
			s[i] %= 100003;
		}
		//printf("s[%d]=%d\n", i, s[i]);
	}
	
	printf("%d", s[n]);
	
	return 0;
}
