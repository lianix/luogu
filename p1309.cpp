#include <bits/stdc++.h>
using namespace std;

struct person {
	int s;
	int w;
	int id;
}; 

int n, r, q;

person p[100008];

int start, end;

bool compare(person p1, person p2)
{
	return p1.s > p2.s;	
}

int main()
{
	scanf("%d %d %d", &n, &r, &q);
	n = 2*n; 
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i].s);
		p[i].id = i;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i].w);
	}
	
	sort(p, p+n, compare);
	for(int i = 1; i < n; i++){
	
	}
	
	
}
