#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

int n, k;
int ansmin[MAXN], ansmax[MAXN];

struct Node {
	int v;
	int idx; 
};
Node a[MAXN];

deque <Node> q;

void min_q()
{	 
	q.clear();
		
	for(int i = 1; i <= n; i++) {
		while(!q.empty() && a[i].v < q.back().v) {
			q.pop_back();
		}
		q.push_back(a[i]);
		
		while(q.front().idx <= i - k)
			q.pop_front();
				
		if(i >= k)
			ansmin[i] = q.front().v;
	}
}

void max_q()
{	 
	q.clear();
		
	for(int i = 1; i <= n; i++) {
		while(!q.empty() && a[i].v > q.back().v) {
			q.pop_back();
		}
		q.push_back(a[i]);
		
		while(q.front().idx <= i - k)
			q.pop_front();
				
		if(i >= k)
			ansmax[i] = q.front().v;
	}
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &k);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i].v);
		a[i].idx = i;
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
