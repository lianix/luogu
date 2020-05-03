#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+6;

int n, m;

struct Node {
	int v;
	int idx; 
};

deque <Node> q;

int main()
{
	int i, x;
	
	scanf("%d %d", &n, &m);
	
	printf("0\n");
	for(i = 1; i <= n; i++) {
		Node a;
		scanf("%d", &a.v);
		a.idx = i;
		
		if(i > 1)	
			printf("%d\n", q.front().v);
			
		while(!q.empty() && a.v < q.back().v) {
			q.pop_back();
		}
		q.push_back(a);
		
		while(q.front().idx <= i - m)
			q.pop_front();
	}
		
	return 0;
}
