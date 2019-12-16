#include <bits/stdc++.h>
using namespace std;

long long a, b, n, p, sum;
 
int main()
{
	cin >> a >> b >> n;
	
	long long next;
	sum += a;
	p = b - a;
	next = a;
	
	for(int i = 1 ; i < n; i++) {
		next = next + p;
		sum += next;	 
	}
	
	cout << sum;
	
	return 0;
}
