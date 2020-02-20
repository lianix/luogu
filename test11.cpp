#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i;
	
	for(i = 1; i < 140; i++) {
		int ans = 0;
		int k = i, remain = 0;
		cout <<"start " << i << endl;
		while(k) {
			ans += k;
			k += remain;
			remain = k % 3;
			k = k / 3;
			cout << k << " " << remain<< "==";
		}
		if(remain == 2)
			ans += 1;
			
		if(ans >= 140)
			break;
	}
	
	cout << i;
}
