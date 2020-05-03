#include <bits/stdc++.h>
using namespace std;

int b[5000];
int ans[12];

struct CC {
	int n;
	int a;
	int id;
};
CC c[12]; 

int t;

bool cmp(CC c1, CC c2) {
	return c1.n <= c2.n; 
}

void multiply(int b[], int x)
{
	int y = 0;
	for(int i = 1; i <= b[0]; i++) {
		b[i] = b[i] * x + y;
		y = b[i] / 10;
		b[i] %= 10;
	}
	
	while(y != 0) {
		b[0]++;
		b[b[0]] = y % 10;
		y /= 10;
	}
}

int main()
{
	scanf("%d", &t);
	int i;
	for(i = 0; i < t; i++) {
		scanf("%d %d", &(c[i].n), &(c[i].a));
		c[i].id = i;
	}
	
	sort(c, c+t, cmp);
	
	int idx = 0;
	b[0] = 1;
	b[1] = 1;
	for(i = 0; i <= c[t-1].n; i++) {
		if(i == 0) {
			b[0] = 1;
			b[1] = 1;
		} else {
			multiply(b, i);
		}
		
		if(i == c[idx].n) {
			for(int j = 1; j <= b[0]; j++) {
				if(b[j] == c[idx].a) {
					ans[c[idx].id]++;
				}		
			}
			idx++;
		}
	}
	
	for(i = 0; i < t; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
