#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, n2, i;
	cin >> n;
	
	n2 = sqrt(n);
	for(i = 1; i <= n2; i++) {
		cout <<i*i <<" ";
	}
	
	return 0;
 } 
