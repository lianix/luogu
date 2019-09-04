#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int k,n;
	double s;
	cin >> k;
	n = 1;
	s = 1;
	while(s <= k){
		n++;
		s+=1.0/n;
	}
	
	cout << n;
	return 0;
}
