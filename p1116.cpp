#include<bits/stdc++.h>
using namespace std;

int a[10002];
int n, cnt;

int main()
{
	int i;
	
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> a[i];
	
	int tmp;
	for(i = n-1; i >= 1; i--)
		for(int j = 0; j < i; j++) {
			if(a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				cnt++;
			}
		}
		
	cout << cnt; 
}
