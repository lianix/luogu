#include <bits/stdc++.h>
using namespace std;

int m, n, k, l, d;
int x, y, p,q;
int a[1008];
int b[1008];
int a1[1008], b1[1008];
int main()
{
	scanf("%d %d %d %d %d", &m, &n, &k, &l, &d);
	for(int i = 0; i < d; i++)
	{
		scanf("%d %d %d %d", &x, &y, &p, &q);
		if(x == p)
		{
			if(y==q)
				continue;
			
			if(y < q)
				b[y]++;
			else
				b[q]++;
			
		} else {
		  	if(x<p)
		  		a[x]++;
		  	else
		  		a[p]++;
		  }  
	}
/*	
	for(int i = 1; i <=m; i++)
	{
		printf("a[%d]=%d\n", i, a[i]);
	}
	for(int i = 1; i <=n; i++)
	{
		printf("b[%d]=%d\n", i, b[i]);
	}
*/
	memcpy(a1, a, sizeof(a));
	sort(a1+1, a1 + m);
	int flag = a1[m-k];
//	printf("a flag=%d\n", flag);
	int j = 0;
	for(int i = 1; i < m; i++) {
		if(a[i] < flag )
			continue;
		j++;
		if (j == k) {
			printf("%d\n", i);
			break;
		}
		printf("%d ", i);	
	}
	
	memcpy(b1, b, sizeof(b));
	sort(b1 + 1, b1+n);
	flag = b1[n-l];
//	printf("b flag=%d\n", flag);
	j = 0;
	for(int i = 1; i < n; i++) {
		if(b[i] < flag )
			continue;
		j++;
		if (j == l) {
			printf("%d", i);
			break;
		}
		printf("%d ", i);	
	}

	return 0;
}

