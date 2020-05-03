#include <bits/stdc++.h> 

using namespace std;

int n;
unsigned long long ans;

int main()
{
	cin >> n;
	
	// the number between point 1 and point n
	for(int i = 3; i <= n - 1; i++) {
		unsigned long long left = i - 1 - 1;  // the point number on the left
		unsigned long long right = n - i;    // the point number on the left
		ans += left * right;
	}
			

	printf("%llu", ans * n / 4);
	
	return 0;
}
