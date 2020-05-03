#include <iostream>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	
	int large, middle, small;
	
	large = max(a, b);
	large = max(large, c);
	
	small = min(a, b);
	small = min(small, c);
	
	middle = a + b + c - large - small;
	
	if(middle + small <= large) {
		cout << "Not triangle" << endl;
		return 0;
	}
	
	if( small * small + middle * middle == large * large) {
		cout << "Right triangle" << endl;
	} else if( small * small + middle * middle > large * large) {
		cout << "Acute triangle" << endl;
	} else {
	 	cout << "Obtuse triangle" << endl;
	 } 
	
	if(large == middle || middle == small) {
		cout << "Isosceles triangle" << endl;
	}
	
	if (large == small) {
		cout << "Equilateral triangle" << endl;
	}
	
	return 0;
}
