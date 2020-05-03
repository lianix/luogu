#include <iostream>
using namespace std;

char a, b;

int main()
{
	cin >> a;
	if(a >= 'a' && a <= 'z')
		b = a -'a' + 'A';
	
	cout << b;
	
	return 0;	
} 
