#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200002;
int a[MAXN];

struct Tree {
	int start, end;
	int max;
};
Tree t[MAXN * 4];

int  n, m;

inline int lt(int r) 
{
	return r << 1;
}
inline int rt(int r)
{
	return (r << 1) | 1;
}
inline void combine(int r) 
{
	t[r].max = max(t[lt(r)].max, t[rt(r)].max);
}

void build(int r, int start, int end)
{
	t[r].start = start;
	t[r].end = end;
	
	if(start == end) {
		t[r].max = a[start];
		return;
	}
	
	int mid = (start + end) >> 1; 
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
}

void update(int r, int x, int k)
{
	if(t[r].start == x && x == t[r].end) {
		t[r].max = max(t[r].max, k);
		return;
	}	
	
	int mid = (t[r].start + t[r].end) >> 1;
	
	if(x <= mid)
		update(lt(r), x, k);
	else
		update(rt(r), x, k);
	
	combine(r);	
}

int query(int r, int x, int y)
{
	if(x <= t[r].start && y >= t[r].end) {
		return t[r].max;
	}	
	
	int mid = (t[r].start + t[r].end) >> 1;
	int max1 = 0, max2 = 0;
	if(x <= mid)
		max1 = query(lt(r), x, y);
	if(y > mid)
		max2 = query(rt(r), x, y);
	
	return max(max1, max2);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	build(1, 1, n);
	
	char op[10];
	int x, y;
	for(int i = 1; i <= m; i++) {
 		scanf("%s %d %d", &op, &x, &y);
 		if(op[0] == 'Q') {
 			printf("%d\n", query(1, x, y));
		 } else {
		 	update(1, x, y);
		 }
 	}
 
 	return 0;
 }
