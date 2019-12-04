#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;


int main()
{
	for(int i = 0; i < 8; i++) {
		scanf("%1d", &n);
		if(n == 1)
			cnt++;
	}
	
	printf("%d", cnt);	
	return 0;
}

