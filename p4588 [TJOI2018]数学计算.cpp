#include<bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 1e5+2;

struct Tree {
    int start, end;
    long long mul;
};
Tree t[MAXN * 4];

int n, q, p;
int op, m;

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
	t[r].mul = (t[lt(r)].mul * t[rt(r)].mul) % p;
}

void build(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	
	if(start == end) {
		t[r]. mul = 1;
		return;
	}
	
	int mid = (start + end) >> 1;
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
	debug("t[%d]:%d - %d sum:%lld\n", r, start, end, t[r].sum);
} 

void update(int r, int x, long long k)
{
    if(t[r].start == t[r].end) {
        t[r].mul = k % p;
        return;
    }

    int mid = (t[r].start + t[r].end) >> 1;
    
    if (x <= mid)
		update(lt(r), x, k);
   else 
		update(rt(r), x, k);
		
    combine(r);
}

long long query(int r, int x, int y)
{
    if( x <= t[r].start && y >= t[r].end)
		return t[r].mul;

    int mid = (t[r].start + t[r].end) >> 1;
    long long ans = 0;
    if(x <= mid) ans *= query(lt(r), x, y);
    if(y > mid) ans *= query(rt(r), x, y);
    
    return ans % p;
}

int main()
{
	int i, j;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &q, &p);
		build(1, 1, q);
		
		for(j = 1; j <= q; j++) {
			scanf("%d %lld", &op, &m);
			if(op == 1) {
				update(1, j, m);
				printf("%lld\n", query(1, 1, q));
			} else {
				update(1, m, 1);
				printf("%lld\n", query(1, 1, q));
			}
		}
	}

	return 0;
}
