#include <bits/stdc++.h>

using namespace std;

int maxl, curl = 1;
int n, nextn = 0;
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &n);
		
		if(n == nextn) {
			curl++;
			nextn = n+1;
		} else {
			nextn = n+1;
			maxl = max(maxl, curl);
			curl = 1;
		}
	}
	
	maxl = max(maxl, curl);
	
	printf("%d\n", maxl);
	
	return 0;
}

