#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+6;

int n, k;

struct Node {
	int v;
	int idx; 
};

deque <Node> q;

int main()
{
	int i, x;
	
	scanf("%d %d", &n, &k);
	
	for(i = 1; i <= n; i++) {
		Node a;
		scanf("%d", &a.v);
		a.idx = i;
		
		while(!q.empty() && a.v > q.back().v) {
			q.pop_back();
		}
		q.push_back(a);
		
		while(q.front().idx <= i - k)
			q.pop_front();
				
		if(i >= k)
			printf("%d\n", q.front().v);
	}
		
	return 0;
}
