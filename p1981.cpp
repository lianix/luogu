#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int a;
char c;
int flag;

int main()
{
	//freopen("P1981_2.in", "r", stdin);
	//freopen("P1981_2.out", "w", stdout);
	while((c = getchar()) != EOF) {
		if ( c == '+') {
			a = a % 10000;
			if(flag == 1) { // *
				a = a * s.top();
				a = a % 10000;
				s.pop();
				s.push(a);
			} else {
				s.push(a);
			}
			a = 0;
			flag = 0;
		} else if (c == '*') {
			a = a % 10000;
			if(flag == 1) { // *
				a = a * s.top();
				a = a % 10000;
				s.pop();
				s.push(a);
			} else {
				s.push(a);
			}
			a = 0;
			flag = 1;
		} else if (c >= '0' && c <= '9') {
			a = a * 10 + (c - '0');
		}	
	}
	
	a = a % 10000;
	if(flag == 1) {
		a = a * s.top();
		a = a % 10000;
		s.pop();
	}

	while(!s.empty()) {
		a = a + s.top();
		a = a % 10000;
		s.pop();
	}

	printf("%d", a);
	return 0;
}
