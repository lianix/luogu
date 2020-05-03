#include<bits/stdc++.h>
using namespace std;

string *p[10002];
string pre;
int  len;
int n;

bool cmp(string *p1, string *p2)
{
	return *p1 < *p2;
}

bool prefix(string *p1)
{
	if(p1->size() < len)
		return false;
		
	for(int i = 0; i < len; i++) {
		if((*p1)[i] != pre[i])
			return false;
	}
	
	return true;
}

int main()
{
	int i;
	string s;
	
	cin >> n;
	
	for(i = 1; i <= n; i++) {
		cin >> s;
		string *pp = new string(s);
		p[i] = pp;		
	}    
	
	cin >> pre;
	len = pre.size();
	
	int idx = 1;
	for(i = 1; i <= n; i++) {
		if(prefix(p[i]))
			p[idx++] = p[i];	
	}    
	
	sort(p+1, p+idx, cmp);
	for(i = 1; i < idx; i++) {
		cout << *(p[i])<<	endl;
	}    
	
	return 0;
}
