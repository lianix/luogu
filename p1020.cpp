#include <bits/stdc++.h>
using namespace std;

const int maxn=100002;
int cnt;
int h[maxn], f[maxn], fidx, e[maxn], eidx;

bool cmp(const int& a1, const int& a2)
{
	return a1 > a2;
}

int main()
{
    int i;
    int h1;
	while(scanf("%d", &h1) != EOF) {
		h[cnt++] = h1;
	}
	
	fidx++;
	eidx++;
	f[fidx] = h[0];
	e[eidx] = h[0];
	for(i = 1; i < cnt; i++) {
		if(f[fidx] >= h[i]) {
			fidx++;
			f[fidx] = h[i];	
		} else {
			int *p = upper_bound(f+1, f+fidx+1, h[i], cmp);
			*p = h[i];
		}
		
		if(e[eidx] < h[i]) {
			eidx++;
			e[eidx] = h[i];
		} else {
			int *p = lower_bound(e+1, e+eidx+1, h[i]);
			*p = h[i];
		}
	}
    
    printf("%d\n%d", fidx, eidx);
    return 0;
}
