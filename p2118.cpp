#include <bits/stdc++.h>
using namespace std;

int a, b, lim, a1, b1, af, bf;
double c, tmp, tmp1, bmin = 100.0;

bool isCoprime(int x, int y)
{
	if(x==1 || y==1)
	    return true;
	
	int tmp=0;
    while(true) {
		tmp=x%y;
		if(tmp==0) {
			break;
		}
		else {
			x=y;
			y=tmp;
		}
	}
	if(y==1)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d %d %d", &a, &b, &lim);
	c= 1.0 * a / b;
	for(a1 = 1; a1 <= lim; a1++) //·Ö×Ó 
		for(b1 = 1; b1 <= lim; b1++) { //·ÖÄ¸ 
			tmp1 = 1.0 * a1 / b1;
			if(tmp1 < c)
				continue;
				
			tmp = fabs(c - tmp1); 
			if(tmp <= bmin) {
				if(isCoprime(a1, b1)) {
					af = a1; 
					bf = b1;
					bmin = tmp;
				}	
			}	
		}

	printf("%d %d", af, bf);
	
	return 0;	
}
