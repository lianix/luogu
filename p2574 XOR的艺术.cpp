#include<bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 2e5+2;

char a[MAXN];

struct Tree {
    int start, end;
    int sum;
	bool flag;
};
Tree t[MAXN * 4];

int n, m;
int op, x, y;

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

void combine(int r)
{
	t[r].sum = t[lt(r)].sum + t[rt(r)].sum;
	debug("t[%d]:%d - %d sum:%d\n", r, t[r].start, t[r].end, t[r].sum);
}

void bulid(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	t[r].flag = false;
	
	if(start == end) {
		t[r]. sum = a[start] - '0';
		debug("t[%d]:%d - %d sum:%d\n", r, t[r].start, t[r].end, t[r].sum);
		return;
	}
	
	int mid = (start + end) >> 1;
	bulid(lt(r), start, mid);
	bulid(rt(r), mid + 1, end);
	combine(r);
} 

void push_down(int r) {
    if(t[r].flag) {
    	int x = lt(r);
        t[x].sum = count(x) - t[x].sum;
        t[x].flag = !t[x].flag;
		debug("t[%d]:%d - %d sum:%d\n", r, t[r].start, t[r].end, t[r].sum);
	
		x = rt(r);
		t[x].sum = count(x) - t[x].sum;
        t[x].flag = !t[x].flag;	
		debug("t[%d]:%d - %d sum:%d\n", r, t[r].start, t[r].end, t[r].sum);
	
        t[r].flag = false;
    }
}

void update(int r, int x, int y)
{
    if(x <= t[r].start && y >= t[r].end) {
        t[r].sum = count(r) - t[r].sum;;
        t[r].flag = !t[r].flag;
        debug("t[%d]:%d - %d sum:%d\n", r, t[r].start, t[r].end, t[r].sum);
        return;
    }

    push_down(r);

    int mid = (t[r].start + t[r].end) >> 1;
    
    if (x <= mid)
		update(lt(r), x, y);
		
    if( y > mid)
		update(rt(r), x, y);
		
    combine(r);
}

int query(int r, int x, int y)
{
    if( x <= t[r].start && y >= t[r].end)
		return t[r].sum;

    push_down(r);
    
    int mid = (t[r].start + t[r].end) >> 1;
    int ans = 0;
    if(x <= mid) ans += query(lt(r), x, y);
    if(y > mid) ans += query(rt(r), x, y);
    
    return ans;
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &m);
	scanf("%s", &a[1]);
	
	bulid(1, 1, n);
	
	for(i = 1; i <= m; i++) {
		scanf("%d %d %d", &op, &x, &y);
		if(op == 0) {
			update(1, x, y);
		} else {
			printf("%d\n", query(1, x, y));
		}
	}

	return 0;
}
