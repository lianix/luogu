#include <bits/stdc++.h>
using namespace std;

int n, q;
int book[1008];
int bmin, pos;
int len, req;

int main()
{
	int i;
	
	scanf("%d %d", &n, &q);
	for(i=1; i <=n; i++) {
		scanf("%d", &book[i]);
	}
	book[0] = -1;
	
	int tmp, mask;
	for(int j=1; j <= q; j++) {
		scanf("%d %d", &len, &req);
	
		mask = 1;
		while(len) {
			mask = mask * 10;
			len--;
		}
		bmin = 10000001;
		pos = 0;
		
		for(i=1; i <=n; i++) {
			tmp = book[i] - req;
			if(tmp % mask != 0)
				continue;
			
			if(tmp < bmin ) {
				bmin = tmp;
				pos = i;
			}
			if(bmin == 0)
				break;	
		}
		printf("%d\n", book[pos]);
	}
	
	return 0;		
}
