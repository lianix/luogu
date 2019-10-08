#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100008];
int sum, cnt;

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	sum = 0;
	for(i = 0; i < n; i++) {
		sum += a[i];
		if(sum > m) {
			cnt++;
			sum = a[i];
		}
	}
	cnt++;
	
	printf("%d", cnt);
	return 0;
}
