#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...) 
#endif

list <string> slist;
list <string>::iterator it;
string a;

int main()
{
	while(cin >> a) {
		int start = 0, end = 0;
		string a1;
		slist.clear();
		it = slist.begin();
		while((end = a.find_first_of("[]", start)) != string::npos)
		{
			debug("start= %d, end =%d\n", start, end);
			a1 = a.substr(start, end - start);
			slist.insert(it, a1);
			if(a[end] == '[')
				it = slist.begin();
			else
				it = slist.end();
			start = end + 1;
		}
	
		a1 = a.substr(start);
		slist.insert(it, a1);
	
		for(it = slist.begin(); it != slist.end(); it++) {
			cout << *it;
		}
		printf("\n");	
	}
		
	return 0;
}
