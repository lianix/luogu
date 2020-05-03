#include <iostream>
using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	
	int big, small;
	
	if (a > b) {
		big = a;
		small  = b;
	} else {
		big = b;
		small = a;
	}
	
	if(c > big) {
		cout <<  small << " " << big << " "  <<  c ;
	} else {
		if (c > small)
			cout << small  << " " << c << " "  << big ;
		else
			cout  << c  << " "    << small   << " " <<  big  ;
	}
		
	return 0;
}
