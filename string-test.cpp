#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	cout << s << endl;
	
	int pos = s.find("12", 2);
	if(pos == s.npos)
		printf("not found\n");
	else
		printf("pos = %d\n", pos);	
		
	return 0;
}
