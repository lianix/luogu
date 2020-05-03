#include <iostream>
using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
int year, month;

int main()
{
	cin >> year >> month;
	
	if (month != 2) {
		cout << a[month] ;
		return 0;
	}	
	
	if(year % 400 == 0) {
		cout << a[2] + 1;
		return 0;
	}
	
	if(year % 100 != 0 && year % 4 == 0)  {
		cout << a[2] + 1;
		return 0;
	}
		
	cout << a[2];
	
	return 0;
}
