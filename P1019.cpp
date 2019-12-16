#include <bits/stdc++.h>
using namespace std;

string str[22];
int cnt[22];

int n, maxlen;
string ss;

dfs(int idx, int len)
{
	int pos;
	
	char last = str[idx][string.size() - 1];
	for(int i = 0; i < n; i++) {
		if(pos = str[idx].find(last) == string::npos)
			continue;
		if(str[idx].size() <= pos + 1)
			continue;
		
		if(str[idx].compare())
		
		
	}
		
}


int main()
{
	cin >> n;
	for(int i = 0; i <= n; i++)
		cin >> str[i];
	
	for(int i = 0; i < n; i++)
		if(str[i][0] == str[n][0]);
			dfs(i);
		
	printf("%d", maxlen);
}
