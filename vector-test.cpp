#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n, t, ans;
	cin >> m >> n;
	
	vector<int> v(20, 1);
	printf("sizeof: %d", sizeof(v));
	printf("size: %d", v.size());
	printf("cap: %d", v.capacity());
	printf("%p: %p", v.begin(), v.end());
	return 0;
}
