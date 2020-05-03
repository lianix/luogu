#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;

long a[MAXN];
int n;

int main()
{
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a+1, a+1+n);
	
	int li, si;
	
	li = n; si = 1;
	while(li >= si) {
		if( li == si) {
			cout << a[li] << endl;
			return 0;
		}

		cout << a[li] << endl;
		cout << a[si] << endl;
		
		li--;
		si++;	
	}
	
	return 0;
}
