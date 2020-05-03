#include<bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 1e5+2;

int a[MAXN];

struct Tree {
    int start, end;
    long long add, mul, sum;
};
Tree t[MAXN * 4];

int n, m, p;
int op, x, y, k;

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
	t[r].sum %= p;
		
	debug("t[%d]:%d - %d sum:%lld\n",
		   r, t[r].start,
		   t[r].end, t[r].sum);
}

void bulid(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	t[r].mul = 1;

	if(start == end) {
		t[r].sum = a[start];
		return;
	}
	
	int mid = (start + end) >> 1;
	bulid(lt(r), start, mid);
	bulid(rt(r), mid + 1, end);
	combine(r);
	debug("t[%d]:%d - %d sum:%lld\n", r, start, end, t[r].sum);
} 

void push_down(int r) {
	int i = lt(r);
	t[i].sum = t[i].sum * t[r].mul + t[r].add * count(i);
    t[i].sum %= p;
	t[i].mul *= t[r].mul;
	t[i].mul %= p;
    t[i].add = t[i].add * t[r].mul + t[r].add;
    t[i].add %= p;

	i = rt(r);
	t[i].sum = t[i].sum * t[r].mul + t[r].add * count(i);
    t[i].sum %= p;
	t[i].mul *= t[r].mul;
	t[i].mul %= p;
    t[i].add = t[i].add * t[r].mul + t[r].add;
    t[i].add %= p;
    
    t[r].add = 0;
    t[r].mul = 1;
}

void update_add(int r, int x, int y, int k)
{
    if(x <= t[r].start && y >= t[r].end) {
        t[r].sum += k * count(r);
        t[r].sum %= p;
        t[r].add += k;
        t[r].add %= p;
        return;
    }

    push_down(r);

    int mid = (t[r].start + t[r].end) >> 1;
    
    if (x <= mid)
		update_add(lt(r), x, y, k);
		
    if( y > mid)
		update_add(rt(r), x, y, k);
		
    combine(r);
}

void update_mul(int r, int x, int y, int k)
{
    if(x <= t[r].start && y >= t[r].end) {
        t[r].sum *= k;
        t[r].sum %= p;
        t[r].mul *= k;
        t[r].mul %= p;
        t[r].add *= k;
        t[r].add %= p;
        return;
    }

    push_down(r);

    int mid = (t[r].start + t[r].end) >> 1;
    
    if (x <= mid)
		update_mul(lt(r), x, y, k);
		
    if( y > mid)
		update_mul(rt(r), x, y, k);
		
    combine(r);
}

long long query(int r, int x, int y)
{
    if( x <= t[r].start && y >= t[r].end)
		return t[r].sum;

    push_down(r);
    
    int mid = (t[r].start + t[r].end) >> 1;
    long long ans = 0;
    
    if(x <= mid) ans += query(lt(r), x, y);
    if(y > mid) ans += query(rt(r), x, y);
    
    return ans % p;
}

int main()
{
	int i;
	
	scanf("%d %d %d", &n, &m, &p);
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	bulid(1, 1, n);
	
	for(i = 1; i <= m; i++) {
		scanf("%d %d %d", &op, &x, &y);
		if(op == 1) {
			scanf("%d", &k);
			update_mul(1, x, y, k);
		} else if(op == 2) {
			scanf("%d", &k);
			update_add(1, x, y, k);
		} else {
			printf("%lld\n", query(1, x, y));
		}
	}

	return 0;
}
