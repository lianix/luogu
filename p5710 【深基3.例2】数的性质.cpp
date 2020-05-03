#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	
	bool even = (a & 1)== 0;
	bool flag2 = (a > 4) && (a <=12);
	
	if (even && flag2)
		cout << 1 << " ";
	else
		cout << 0 << " ";
		
	if (even || flag2)
		cout << 1 << " ";
	else
		cout << 0 << " ";
		
	if ((even && (!flag2)) ||
	    (!even) && (flag2) )
	    cout << 1 << " ";
	else
		cout << 0 << " ";
	
	if ((!even) && (!flag2))
		cout << 1 << " ";
	else
		cout << 0 << " ";	
	
	return 0;
}
