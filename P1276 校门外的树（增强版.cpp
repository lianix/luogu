#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 10004;
int a[MAXN];
int L, n;
long long remove_total, total;

struct Tree {
	int start, end;
	int flag; /*0 -> cut  1 -> plant */

	int smalltree;
	int bigtree;
	int remove;
};

Tree t[4 * MAXN];

inline int lt(int r)
{
	return r << 1;	
}

inline int rt(int r)
{
	return (r << 1) | 1;	
}

inline int count(int r)
{
	return t[r].end - t[r].start + 1;
}

inline void combine(int r)
{
	t[r].smalltree = t[lt(r)].smalltree + t[rt(r)].smalltree;
	t[r].bigtree = t[lt(r)].bigtree + t[rt(r)].bigtree;

	t[r].remove = t[lt(r)].remove + t[rt(r)].remove;
	
	debug("t[%d] %d-%d big: %d small:%d remove:%d\n",
			r, t[r].start, t[r].end,
			t[r].bigtree, t[r].smalltree, t[r].remove);
}

void build(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	t[r].flag = 1;
	
	if(start == end) {
		t[r].remove = 0;
		t[r].smalltree = 0; 
		t[r].bigtree = 1;
		return;
	}
	
	int mid = (start + end) >> 1;
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
}

void update_node(int r, int flag) {
	if (flag == 1) {
		if(t[r].bigtree == 0)
			t[r].smalltree = count(r);
		t[r].remove = 0;
	} else {
		remove_total += t[r].smalltree;
		t[r].remove = count(r);
		t[r].smalltree = 0;
		t[r].bigtree = 0;
	}
	
	debug("t[%d] %d-%d big: %d small:%d remove:%d\n",
		r, t[r].start, t[r].end,
		t[r].bigtree, t[r].smalltree, t[r].remove);
}

void push_down(int r)
{
	int x;
	if(t[r].remove == count(r)) {
		x = lt(r);
		t[x].remove = count(x);
		t[x].smalltree = 0;
		t[x].bigtree = 0;
		
		x = rt(r);
		t[x].remove = count(x);
		t[x].smalltree = 0;
		t[x].bigtree = 0;
		
		return;
	}
	
	if (t[r].bigtree == count(r) ) {
		x = lt(r);
		t[x].remove = 0;
		t[x].smalltree = 0;
		t[x].bigtree = count(x);
		
		x = rt(r);
		t[x].remove = 0;
		t[x].smalltree = 0;
		t[x].bigtree = count(x);
		
		return;
	}
	
	if (t[r].smalltree == count(r)) {
		x = lt(r);
		t[x].remove = 0;
		t[x].smalltree = count(x);
		t[x].bigtree = 0;
		
		x = rt(r);
		t[x].remove = 0;
		t[x].smalltree = count(x);
		t[x].bigtree = 0;
		
		return;
	}	
}
void update(int r, int x, int y, int flag)
{
	if(x <= t[r].start && y >= t[r].end) {
		if(t[r].remove == count(r) ||
		   t[r].bigtree == count(r) ||
		   t[r].smalltree == count(r)) {
			update_node(r, flag);
			return ;
		}	
	}
	
	push_down(r);
	
	int mid = (t[r].start + t[r].end ) >> 1;	
	if(x <= mid)
		update(lt(r), x, y, flag);
	if(y > mid)
		update(rt(r), x, y, flag);
		
	combine(r);
}

int main()
{
	int i;
	
	scanf("%d %d", &L, &n);
	
	build(1, 0, L);
	
	int op, x, y;
	
	for(i = 1; i <= n; i++) {
		scanf("%d %d %d", &op, &x, &y);
		update(1, x, y, op);	
	}

	printf("%d\n%d\n", t[1].smalltree, remove_total);
	
	return 0;
}
