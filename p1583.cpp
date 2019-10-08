#include <bits/stdc++.h>
using namespace std;

int e[11];
int n, k;
struct person {
	int idx;
	int w;
}; 

person p[20008];
person *p1[20008];
person *p2[20008];

void insert(person **p1ist, person *pp, int m)
{
	do {
		if(m == 0) {
			p1ist[0] = pp;
			return;
		}

		if(p1ist[m-1]->w < pp->w) {
			p1ist[m] = p1ist[m-1];
			continue;	
		} else if(p1ist[m-1]->w == pp->w &&
				  p1ist[m-1]->idx > pp->idx)
		{
			p1ist[m] = p1ist[m-1];
			continue;
		} else {
			p1ist[m] = pp;
			return;
		}
	} while(m--);
}

int main() 
{	
	int i;
	
	scanf("%d %d", &n, &k);
	for(i = 0; i < 10; i++) {
		scanf("%d", &e[i]);
	}
	
	for(i = 0; i < n; i++) {
		scanf("%d", &p[i].w);
		p[i].idx = i + 1;
		insert(p1, &p[i], i);
	}
	
	for(i = 0; i < n; i++) {
		p1[i]->w += e[i % 10];
		insert(p2, p1[i], i);
	}
	
	for(i = 0; i < k; i++) {
		printf("%d ", p2[i]->idx);
	}
	return 0;
}
