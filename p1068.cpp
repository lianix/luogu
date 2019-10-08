#include <bits/stdc++.h>
using namespace std;

int n,m;
struct A {
	int k;
	int s;
};

A a[5008];

int score, k;

bool compare(A a1, A a2)
{
	if(a1.s > a2.s)
		return true;
	if(a1.s < a2.s)
		return false;
	if(a1.k < a2.k)
		return true;
	else
		return false;
}

void swap(A *a1, A *a2)
{
	A a3;
	a3 = *a1;
	*a1 = *a2;
	*a2 = a3;
}

int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &a[i].k, &a[i].s);
	}

	k = m * 1.5;
	int max;
	for(i = 0; i < n; i++) {
		max = i; 
		for(j = i + 1; j < n; j++ ) {
			if(compare(a[j], a[max]))
				max = j;
		}
		swap(&a[i], &a[max]);
		if(i == k - 1)
			score = a[i].s;
		if(i >= k) {
			if(a[i].s < score)
				break;
		}
	}

	k = i;
	
	printf("%d %d\n", score, k);
	for(i = 0; i < k; i++)
		printf("%d %d\n", a[i].k, a[i].s);
	
	return 0;
}
