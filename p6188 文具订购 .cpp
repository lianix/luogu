#include<bits/stdc++.h>
using namespace std;
int n, u, a, b, c, d;
bool f;
int main()
{
	//freopen("order.in","r",stdin);
	//freopen("order.out","w",stdout);
	scanf("%d", &n);
	u = n / 14;
	d = n % 14;
	if(d==0) {
		printf("%d %d %d", u, u, u);
		return 0;
	}

	while(d<=n) {
		for(c = d / 3; c >= 0; c--) {
			for(b = (d-3*c)/4; b>=0; b--) {
				a = (d - 3*c - 4*b) / 7;
				if(7*a + 4*b + 3*c == d) {
					f=true;
					break;
				}
			}
			if (f)
				break;
		}
		
		if(f)
			break;
		
		u--;
		d += 14;
	}
	
	if(f == false) {
		printf("-1");
		return 0;
	}
	
	printf("%d %d %d", u+a, u+b, u+c);
	return 0;
}
