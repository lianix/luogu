#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main()
{
	cin >> s;
	int len = s.size();
	for(int i = 1; i < len; i++) {
		if(s[i] != s[i-1])
			cnt++;
	}
	
	if(s[len-1] == '0')
			cnt++;
			
	printf("%d", cnt);
	
	return 0;
}

