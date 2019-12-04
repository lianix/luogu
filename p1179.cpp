#include <bits/stdc++.h>
using namespace std;

int l, r, ans;

int cnt(int n)
{
	int m;
	
	while(n) {
		m = n % 10;
		if(m == 2)
			ans++;
		n = n / 10;
	}
}

int main()
{
	scanf("%d %d", &l, &r);
	for(int i = l; i <=r; i++) {
		cnt(i);		
	}
		
	printf("%d", ans);
	return 0;
}
