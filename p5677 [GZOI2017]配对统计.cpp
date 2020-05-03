#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300006;
long long n, m, left, right;
long long ans[MAXN];
long long bit[MAXN*2];

struct A {
	long long d;
	long long idx;
};
A a[MAXN];

struct B {
	long long left;
	long long right;	
} b[MAXN]; 

struct C {
	long long left;
	long long right;
	long long idx;
} c[MAXN];

bool cmpA(A a1, A a2)
{
	return a1.d < a2.d;	
}

bool cmpB(B b1, B b2)
{
	return b1.left < b2.left;	
}

bool cmpC (C c1, C c2) {
    return c1.left < c2.left;
}

long long lowbit(long long x) 
{
	return x & (-x);
}

void add(long long x, long long k)
{
	while(x <= n) {
		bit[x] += k;
		x += lowbit(x);
	}
}

long long sum(long long x)
{
	long long ans1 = 0;
	while(x) {
		ans1 += bit[x];
		x -= lowbit(x);
	}
	
	return ans1;
}

int main()
{
	long long i;
	
	scanf("%lld %lld", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%lld", &a[i].d);
		a[i].idx = i;
	}
	sort(a+1, a+n+1, cmpA);
	
	long long  bidx = 0;
	a[0].d = a[n+1].d = 0x7f7f7f7f;
	for(i = 1; i <= n; i++)	{
		if(abs(a[i].d - a[i-1].d) < abs(a[i+1].d - a[i].d)) {
			bidx++;
			b[bidx].left = min(a[i].idx, a[i-1].idx);
			b[bidx].right = max(a[i].idx, a[i-1].idx);
		} else if(abs(a[i].d - a[i-1].d) > abs(a[i+1].d - a[i].d)) {
			bidx++;
			b[bidx].left = min(a[i].idx, a[i+1].idx);
			b[bidx].right = max(a[i].idx, a[i+1].idx);
		} else {
			bidx++;
			b[bidx].left = min(a[i].idx, a[i-1].idx);
			b[bidx].right = max(a[i].idx, a[i-1].idx);
			bidx++;
			b[bidx].left = min(a[i].idx, a[i+1].idx);
			b[bidx].right = max(a[i].idx, a[i+1].idx);
		}
	}
	sort(b + 1, b + bidx + 1, cmpB);
	
	for(i = 1; i <= m; i++)	{
		scanf("%lld %lld", &c[i].left, &c[i].right);
		c[i].idx= i;
	}
	sort(c + 1, c + m + 1, cmpC);
	
	for(i = m; i >= 1; i--) {
		while(b[bidx].left >= c[i].left) {
			add(b[bidx].right, 1);
			bidx--;
		}
		ans[c[i].idx] = sum(c[i].right);
	}
	
	long long cnt = 0;
    for (i = 1; i <= m; i++) 
		cnt += (ans[i] * i);

 	printf("%lld", cnt);
 	
 	return 0;
}
