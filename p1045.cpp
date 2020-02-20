#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1001;
int p;
int d2[MAXN] = {1, 2,};
int d[MAXN] = {1, 2,}, ans[MAXN] = {1, 1,};

// a = a*b;
void multi(int a[], int b[]) 
{
	int c[MAXN] = {0};
	int len1 = a[0];
	int len2 = b[0];
	int i, j;
	
	for(i = 1; i <= len1; i++) 
		for(j = 1; j <= len2; j++) {
			if((i + j - 1) > 500)
				break;	
			c[i+j-1] += a[i] * b[j];
		}
		
	int x;
	int len3 = len1 + len2 - 1;
	len3 = min(len3, 500);
	for(i = 1; i <= len3; i++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	
	while(c[i]) {
		c[i+1] += c[i] / 10;
		c[i] %= 10;
		i++;
	}
	
	c[0] = i - 1;
	c[0] = min(c[0], 500);
	
	memcpy(a, c, MAXN * 4);
}

void minus(int a[]) {
	for(int i = 1; i < a[0]; i++) {
		if(a[i] >= 1) {
			a[i] = a[i] - 1;
			break;
		} else {
			a[i] = 9 + a[i] - 1;
			a[i+1]--; 
		}
	}
}

int main()
{
	scanf("%d", &p);
	printf("%d\n", int (log10(2) * p + 1));
	while(p) {
		if( p & 1) {
			multi(ans, d);
		}	
		multi(d, d);
		p >>= 1;
	}
	minus(ans);
	
	int i = 500;
	while(i) {
		printf("%d", ans[i]);
		i--;
		if(i % 50 == 0)
			printf("\n");
	}
	
	return 0;
}

