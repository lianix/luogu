#include <iostream>
using namespace std;

int a, b, c;
int k1, k2, k3;
char str[10];

int main()
{
	cin >> k1 >> k2 >> k3;
	cin >> str;
	
	a = min(k1, k2);
	a = min(a, k3);
	c = max(k1, k2);
	c = max(c, k3);
	b = k1 + k2 + k3 - a - c; 

	for(int i = 0; i < 3; i++) {
		switch (str[i]) {
		case 'A':
			cout <<  a << " ";
			break;
		case 'B':
			cout << b << " ";
			break;
		case 'C':
			cout << c << " ";
			break;
		}
	}

	return 0;
}
