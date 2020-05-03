#include<bits/stdc++.h>
using namespace std;

#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

const int MAXN = 100002;

struct Rain {
	int y;
	int r;
	int maybe;
};

Rain a[MAXN];
int an;

struct Tree {
    int start, end;
    int sy, ey;
    int ai;
    int maybe; 
};
Tree t[MAXN * 4];

int n, m;

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
	t[r].maybe = t[lt(r)].maybe | t[rt(r)].maybe;
	t[r].sy = t[lt(r)].sy;
	t[r].ey = t[rt(r)].ey;
	
	if(a[t[lt(r)].ai].r >= a[t[rt(r)].ai].r) {
		t[r].ai = t[lt(r)].ai;
	} else {
		t[r].ai = t[rt(r)].ai;
	}
	
	debug("t[%d]: %d-%d maxai:%d maybe:%d\n",
		  r, t[r].sy, t[r].ey, t[r].ai, t[r].maybe);
}

void build(int r, int start, int end) 
{
	t[r].start = start;
	t[r].end = end;
	
	if(start == end) {
		t[r].ai = start;
		t[r].maybe = a[start].maybe;
		if(start == 1)
			t[r].sy = a[start].y;
		else
			t[r].sy = a[start-1].y + 1;
		t[r].ey = a[start].y;
		//debug("t[%d]: %d-%d maxai:%d maybe:%d\n",
		//		r, t[r].sy, t[r].ey, t[r].ai, t[r].maybe);
		return;
	}
	
	int mid = (start + end) >> 1;
	build(lt(r), start, mid);
	build(rt(r), mid + 1, end);
	combine(r);
} 

Tree query(int r, int y1, int y2)
{
	Tree ans = {0, }, lans= {0, }, rans = {0,};
	
    if( y1 <= t[r].sy && y2 >= t[r].ey) {
    	return t[r];
	}

    if(y2 < t[r].sy || y1 > t[r].ey)
    	return ans;
    
	int lr = lt(r);
    lans = query(lt(r), y1, y2);
    rans = query(rt(r), y1, y2);
    
    if(lans.ai  == 0)
    	return rans;
    if(rans.ai == 0)
    	return lans;
    
    if(a[lans.ai].r >=  a[rans.ai].r) 
		ans.ai = lans.ai;
	else
		ans.ai = rans.ai;
	ans.maybe = lans.maybe | rans.maybe;
	
    return ans;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	
	int yi, ri;
	an = 0;
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &yi, &ri);
		if((i != 1) && yi > (a[an].y + 1)) {
			an++;
			a[an].y = yi-1;
			a[an].maybe = 1;
		} 
		
		an++;
		a[an].y = yi;
		a[an].r = ri;
		a[an].maybe = 0;
	}
	
	build(1, 1, an);
		
	scanf("%d", &m);
		
	int y1, y2;
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &y1, &y2);
		
		if(y1 >= y2) {
			printf("false\n");
			continue;
		}
		
		Tree ans1 = query(1, y1, y1);
		Tree ans2 = query(1, y2, y2);
		Tree maxans = query(1, y1+1, y2);
		
		if(ans1.maybe) {
			u
		}
		if(a[ans2.ai].r >= a[ans2.ai].r) {
			if(ans.maybe)
				printf("maybe\n");
			else
				printf("true\n");
		} else
			printf("false\n");
			
		if(a[ans2.ai].y == y2) {
			if(ans.maybe)
				printf("maybe\n");
			else
				printf("true\n");
		} else
			printf("false\n");
	}

	return 0;
}
