#include <iostream>
using namespace std;

int a;

int main()
{
	cin >> a;
	
	int tlocal = a * 5;
	int tluogu = 11 + a * 3;

	if(tlocal < tluogu)
		cout << "Local";
	else
		cout << "Luogu";
		
	return 0;
}
