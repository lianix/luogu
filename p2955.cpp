#include <bits/stdc++.h>
using namespace std;

char a[100];
int n;

int main()
{
	cin >> n;
	int b, len;
	for(int i = 0; i < n; i++) {
		cin >> a;
		len = strlen(a);
		b = a[len - 1] - '0';
		if(b % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");
	}
	
	return 0;
}
