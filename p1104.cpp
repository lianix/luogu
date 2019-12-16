#include <bits/stdc++.h>
using namespace std;

struct student {
	int idx;
	string name;
	int year;
	int month;
	int date;
};

student s[102];

bool compare(student s1, student s2)
{
	if(s1.year < s2.year)
		return true;
	if(s1.year > s2.year)
		return false;
		
	if(s1.month < s2.month)
		return true;
	if(s1.month > s2.month)
		return false;
		
	if(s1.date < s2.date)
		return true;
	if(s1.date > s2.date)
		return false;
	
	if(s1.idx > s2.idx)
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s[i].name;
		cin >> s[i].year;
		cin >> s[i].month;
		cin >> s[i].date;
		s[i].idx = i;
	}
	
	sort(s+1, s+n+1, compare);
	
	for(int i = 1; i <= n; i++) {
		cout << s[i].name<<endl;
	}
	
    return 0;
}
