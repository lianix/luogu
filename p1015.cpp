#include <bits/stdc++.h>
using namespace std;

char str[102];
int a[250], b[250];
int N;
int lena;

void revers()
{
	for(int i = 0; i < lena; i++) {
		b[lena-i-1] = a[i];
	}
}

bool ishuiwen()
{
	revers();
	
	for(int i = 0; i < lena; i++) {
		if(b[i] != a[i])
			return false;
	}
	
	return true;
}

void sum()
{
	int x=0, i;
	for(i = 0; i < lena; i++) {
		a[i] += b[i] + x;
		x = a[i] / N;
		a[i] %= N; 
	}
	
	if(x > 0) {
		a[i] = x;
		lena = i+1;
	}		
}

int main()
{
	cin >> N;
	cin >> str;
	
	int i;
	lena = strlen(str);
	for(i = 0; i < lena; i++) {
		if(str[i] >= '0' && str[i] <= '9')
			a[lena-i-1] = str[i] - '0';
		else
			a[lena-i-1] = str[i] - 'A' + 10;
	}

	if(ishuiwen()) {
		printf("STEP=0");
		return 0;
	}
	
	for(i = 1; i <= 30; i++) {
		sum();
		if(ishuiwen()) {
			printf("STEP=%d", i);
			return 0;
		}		
	}
	
	printf("Impossible!");
	return 0;
}
