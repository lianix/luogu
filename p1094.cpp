#include <bits/stdc++.h>
using namespace std;

int w, n;
int a[30008];
int cnt;

int main()
{
	int i, j;
	scanf("%d %d", &w, &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	i = 0;
	j = n-1;
	while(i<j) {
		if(a[i] + a[j] > w) {
			cnt++;
			j--;
		} else{
			i++;
			j--;
			cnt++;
		}	
	}
	if(i == j)
		cnt++;
	
	printf("%d", cnt);
}

