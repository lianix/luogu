#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

int n, k;
int a[MAXN], q[MAXN];
int ansmin[MAXN], ansmax[MAXN];

void min_q()
{	
	int front = 1, back = 0;
	
	memset(q, 0, sizeof(q));
	for(int i = 1; i <= n; i++) {	
		while(back >= front && a[q[back]] > a[i])
			back--;
		back++;
		q[back] = i;
		
		while(q[front] <= i - k)
			front++;

		if(i >= k)
			ansmin[i] = a[q[front]];
	}
}

void max_q()
{	 
	int front = 1, back = 0;
	
	memset(q, 0, sizeof(q));

	for(int i = 1; i <= n; i++) {	
		while(back >= front && a[q[back]] < a[i])
			back--;
		back++;
		q[back] = i;
		
		while(q[front] <= i - k)
			front++;
	
		if(i >= k)
			ansmax[i] = a[q[front]];
	}
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &k);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	min_q();
	max_q();
	
	for(int i = k; i <= n; i++) {
		printf("%d ", ansmin[i]);
	}
	printf("\n");
	for(int i = k; i <= n; i++) {
		printf("%d ", ansmax[i]);
	}
	
	return 0;
}
