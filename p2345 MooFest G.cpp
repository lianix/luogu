#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20002;
int n;
long long ans;

struct cow {
	int v;
	int x;
};
cow c[MAXN], tmp[MAXN];

bool cmp(cow &c1, cow &c2)
{
	return c1.v < c2.v;
}

void merge(int left, int mid, int right)
{
	int ai, bi;
	long long total = 0, small = 0;
	
	for(ai = left; ai <= mid; ai++) {
		total += c[ai].x;
	}
	
	ai = left;
	for(bi = mid + 1; bi <= right; bi++) {
		while(ai <= mid && c[ai].x < c[bi].x) { 
			small += c[ai].x;
			ai++;
		}
		
		ans += ((long long) (ai - left) * c[bi].x - small) * c[bi].v;
 		ans += (total - small - ((long long)(mid - ai + 1) * c[bi].x)) * c[bi].v;		
	}
	
	ai = left; bi = mid + 1;
	int ti = left;
	
	while(ai <= mid && bi <= right) {
		if(c[ai].x <= c[bi].x) {
			tmp[ti++] = c[ai++];
		} else
			tmp[ti++] = c[bi++];
	}
	while(ai <= mid)
		tmp[ti++] = c[ai++];
	while(bi <= right) 
		tmp[ti++] = c[bi++];
		
	for(ti = left; ti <= right; ti++)
		c[ti] = tmp[ti];
}

void msort(int left, int right)
{
	if(left >= right)
		return;
	
	int mid = (left + right) >> 1;
	msort(left, mid);
	msort(mid + 1, right);
	merge(left, mid, right);
}

int main()
{
	int i;
	scanf("%d", &n);
	
	for(i= 0; i < n; i++) {
		scanf("%d %d", &c[i].v, &c[i].x);
	}
	
	sort(c, c+n, cmp);
	msort(0, n-1);
	
	printf("%lld", ans);
	
	return 0;
}
