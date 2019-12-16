#include <bits/stdc++.h>
using namespace std;

int n, a1, a2, flag; //0 ³õÖµ  1ÏÂ½µ,  2ÉÏÉý.  
int cnt;

int main()
{
	cin >> n;
	int a;
	cin >> a1; 
	for(int i = 1; i < n; i++) {
		cin >> a2;
		if(a2 > a1) {
			if (flag == 1) {
				cnt++;
			}
			flag = 2;
		} else if(a2 < a1) {
			flag = 1;
			a1 = a2;
		} else {
			// a1 == a2;
		}
		a1 = a2;
	}
	
	printf("%d", cnt);	
		
	return 0;
}
