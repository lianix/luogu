#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+2;
int a[MAXN], t[MAXN*4];
int n, m;
int opt, x, y;

inline int lt(int r)
{
	return r << 1;
}

inline int rt(int r)
{
	return (r << 1) + 1;
}

inline void combine(int r)
{
	t[r] = t[lt(r)] + t[rt(r)];
}

void build(int r, int s, int e)
{
    if (s == e) {
        t[r] = a[s];
        return;
    }
    
    int m = (s + e) >> 1;
    build(lt(r), s, m);
    build(rt(r), m+1, e);
    combine(r);
}

int query(int r, int ts, int te, int s, int e)
{
 
    if(s <= ts && e >= te)
        return t[r];
        
    int tm = (ts + te) >> 1;

	int ans = 0;
    if(s <= tm)
    	ans += query(lt(r), ts, tm, s, e);
    if(e > tm)
        ans += query(rt(r), tm+1, te, s, e);
        
    return ans;
}

void update(int r, int ts, int te, int x, int k)
{
	if(ts == te) {
		t[r] += k;
		return;
	}
		
	int tm = (ts + te) >> 1;
	if(x <= tm)
		update(lt(r), ts, tm, x, k);
	else
		update(rt(r), tm+1, te, x, k);
	
	combine(r);
}

int main()
{
	int i;
	scanf("%d %d", &n, &m);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	build(1, 1, n);
	
	for(i = 1; i <= m; i++) {
		scanf("%d %d %d", &opt, &x, &y);
		if(opt == 1) {
			update(1, 1, n, x, y);
		} else {
			printf("%d\n", query(1, 1, n, x, y));
		}
	}
	
	return 0;
}
