#include <bits/stdc++.h>
using namespace std;

char a[10];

int main()
{
	scanf("%s", a);
	for(int i = strlen(a)-1; i >= 0; i--)
		printf("%c", a[i]);
}
