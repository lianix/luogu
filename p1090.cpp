#include <bits/stdc++.h>
using namespace std;

int n;
int a[10008];
int total, tmp;

void change(int start)
{
	int i;
	int  tmp = a[start];
	for(i = start+1; i < n; i++) {
		if(a[i] < tmp) {
			a[i-1] = a[i];
		} else
			break;
	} 
	
	a[i-1] = tmp;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a+n);
	
	for(int i = 0; i < n - 1; i++) {
		a[i + 1] = a[i] + a[i + 1];
		total += a[i + 1];
		change(i + 1);
		//sort(a + i + 1, a+n);  //50·Ö 
	}
	
	printf("%d", total);
	
	return 0;
}
