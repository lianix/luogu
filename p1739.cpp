#include <bits/stdc++.h>
using namespace std;

char st[22];
int idx;
char c;

int main()
{
	while(1) {
		c = getchar();
		if(c == '@')
			break;
		if(c== '(') {
			st[idx] = '(';
			idx++;
		}
		if(c == ')') {
			if(idx > 0)
				idx--;
			else {
				printf("NO");
				return 0;
			}
		}	
	}
	
	if(idx != 0)
		printf("NO");
	else
		printf("YES");
		
	return 0;
}
