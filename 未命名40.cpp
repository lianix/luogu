#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 1e5+2;
int n, w, a[MAXN], b[MAXN], ans;

struct Tree {
	int start, end;
	int sum;
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
		t[r].sum = 0;
		return;
	}
	
	int mid = (start + end) >> 1;
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
}

void update(int r, int x, int k)
{
	if(x == t[r].start && x == t[r].end) {
		t[r].sum += k;
		return ;	
	}
	
	int mid = (t[r].start + t[r].end) >> 1;	
	if(x <= mid)
		update(lt(r), x, k);
	if(x > mid)
		update(rt(r), x, k);
		
	combine(r);
}

int query(int r, int x, int y)
{
	if(x <= t[r].start && y >= t[r].end) {
		return t[r].sum;	
	}
	
	int ans = 0;
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
	
	scanf("%d %d", &n, &w);
	
	build(1, 1, 100000);
	
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		update(1, a[i], b[i]);
	}
	if(w == 0) {
		printf("0");
		return 0;
	}
		
	for(i = 1; i <= n; i++) {
		int y = min(100000, a[i] + w - 1);
		ans = max(ans, query(1, a[i], y));
	}

	printf("%d", ans);
	
	return 0;
}
