#include <iostream>
using namespace std;

int a;

int main()
{
	cin >> a;
	if(a == 0)
		cout << "Today, I ate 0 apple." << endl;
	else if(a == 1)
		cout << "Today, I ate 1 apple." << endl;
	else
		cout << "Today, I ate " << a << " apples." << endl;
	
	return 0;
}
