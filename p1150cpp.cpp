#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int main()
{
	int i, r = 0;
	
	cin >> n >> k;
	
	while(n) {
		ans += n;
		n += r;
		r = n % k;
		n /= k;
	}
	
	cout << ans;
	
	return 0;
}
