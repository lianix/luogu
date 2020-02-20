#include<bits/stdc++.h>
using namespace std;

long long x[30006],y[30006];
int  n, m, k; 
int ans[30006];
int idx;

int main()
{
	int i;
	
	cin>>k>>m>>n;
	
	for(i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		if(x[i] == 0 || y[i] * (k/x[i]) >= n) {
			ans[idx++] = i;
		}		
	}
	
	if(idx == 0)
		cout << -1;
	else
		for(i = 0; i < idx; i++)
			cout << ans[i] << " ";
	
	return 0;
}

