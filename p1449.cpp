#include <bits/stdc++.h>
using namespace std;

stack <int> s; 
char str[1008];
char *p, *start, *end;
int a, b;

int main()
{
	scanf("%s", str);
	p = &str[0];
	
	while(*p != '@') {
		if(*p >= '0' && *p <= '9') {
			start = p;
			while(*p != '.')
				p++;
			*p = '\0';
			a = atoi(start);
			s.push(a);	
		}
		else if(*p == '-' ) {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			a = b - a;
			s.push(a);
		}
		else if(*p == '+' ) {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			a = b + a;
			s.push(a);
		}
		else if(*p == '*' ) {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			a = b * a;
			s.push(a);
		}
		else if(*p == '/' ) {
				a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			a = b / a;
			s.push(a);
		}
		
		p++;
	} 
	
	printf("%d", s.top());
	
	return 0;
 } 
