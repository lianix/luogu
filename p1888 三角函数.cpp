#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	cin >> a >> b >> c;
	
	int maxn = max(a, b);
	int minn = min(a, b);
	maxn = max(maxn, c);
	minn = min(minn, c);
	int d = gcd(maxn, minn);
	cout << minn/d << "/" << maxn/d;
	
	return 0;
 } 
