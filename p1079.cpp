#include <bits/stdc++.h>
using namespace std;

string mingwen, key, miwen;
int k[102];
int mw;
int lenkey, lenmiwen;

int main()
{
	cin >> key;
	cin >> miwen;

	lenkey = key.size();
	lenmiwen = miwen.size();
	mingwen.resize(lenmiwen);
	
	for(int i = 0; i < lenkey; i++) {
		if(key[i] >= 'a')
			k[i] = key[i] - 'a';
		else
			k[i] = key[i] - 'A';
	}
	
	for(int i = 0; i < lenmiwen; i++) {
		if(miwen[i] >= 'a') {
			mw = miwen[i] - 'a';
			mingwen[i] = 'a' + ((mw + 26 - k[i % lenkey])%26);
		} else {
			mw = miwen[i] - 'A';
			mingwen[i] = 'A' + ((mw + 26 - k[i % lenkey])%26);
		}	
	}
	
	cout << mingwen;
	
    return 0;
}
