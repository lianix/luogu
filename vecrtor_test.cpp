#include <bits/stdc++.h>
using namespace std;


int main()
{
	vector <int> a;
	vector <int> b;
	a.assign(10,2);
	b = a;
	a[2] = 10;
	 
	printf("%d %d %d ", a.size(), b.size(), b[2]);
	
    return 0;
}
