#include <bits/stdc++.h>
using namespace std;

char str[102];
struct DATA {
	int type;  //0->dropped, 1->data, 2->op
	int data;
	char op;
};
DATA dt[100];
int idx;

stack <char> s;
 
int main()
{
	scanf("%s", str);
	int len = strlen(str);
	int shu = 0;
	for(int i = 0; i < len; i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			shu = shu * 10 + (str[i] - '0');
		} else {
			
			if (str[i] == '-') {
			s.push('-');
			} else if (str[i] == '+') {
				s.push('+');
			} else if (str[i] == '*') {
				s.push('*');
			} else if (str[i] == '/') {
				s.push('/');
			} else if (str[i] == '(') {
				s.push('/');
			} else if (str[i] == ')') {
				s.push('/');
			} 
		} 
	}

	printf("%d", a);
	return 0;
}
