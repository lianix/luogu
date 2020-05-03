#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 2e5+2;
int n, f, a[MAXN];

struct Tree {
	int start, end;
	long long sum;
	int add;
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
	t[r].sum = t[lt(r)].sum + t[rt(r)].sum;
}

void build(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	
	if(start == end) {
		t[r].sum = a[start];
		return;
	}
	
	int mid = (start + end) >> 1;
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
}


void push_down(int r)
{
	int x;
	if(t[r].add) {
		x = lt(r);
		t[x].sum += t[r].add * count(x);
		t[x].add += t[r].add;
	
		x = rt(r);
		t[x].sum += t[r].add * count(x);
		t[x].add += t[r].add;
	}
	
	t[r].add = 0;
}

void update(int r, int x, int y, int k)
{
	if(x <= t[r].start && y >= t[r].end) {
		t[r].sum += k * count(r);
		t[r].add += k;
		return ;	
	}
	
	push_down(r);
	
	int mid = (t[r].start + t[r].end ) >> 1;	
	if(x <= mid)
		update(lt(r), x, y, k);
	if(y > mid)
		update(rt(r), x, y, k);
		
	combine(r);
}

long long query(int r, int x, int y)
{
	if(x <= t[r].start && y >= t[r].end) {
		return t[r].sum;	
	}
	
	push_down(r);
	
	long long ans = 0;
	int mid = (t[r].start + t[r].end ) >> 1;	
	if(x <= mid)
		ans += query(lt(r), x, y);
	if(y > mid)
		ans += query(rt(r), x, y);
		
	return ans;
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &f);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	
	int op, x, y, k;
	
	for(i = 1; i <= f; i++) {
		scanf("%d", &op);
		switch(op) {
		case 1:
			scanf("%d %d %d", &x, &y, &k);
			update(1, x, y, k);
			break;
		case 2:
			scanf("%d", &k);
			update(1, 1, 1, k);
			break;
		case 3:
			scanf("%d", &k);
			update(1, 1, 1, -k);
			break;
		case 4:
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(1, x, y));
			break;
		case 5:
			printf("%lld\n", query(1, 1, 1));
			break;	
		}
	}

	return 0;
}
