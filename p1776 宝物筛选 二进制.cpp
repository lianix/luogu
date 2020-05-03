#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <algorithm>
 
using namespace std;

int v[105], w[105], m[105];
int nv[2000], nw[2000], nm[2000], nidx;
int n, BW, f[50006];

int main()
{
	int i, j;
	scanf("%d %d", &n, &BW);
	
	for(i = 1; i <= n; i++){ 
		scanf("%d %d %d", &v[i], &w[i], &m[i]);
	}
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j < m[i]; j *= 2) {
			m[i] = m[i] - j;
			nidx++;
			nv[nidx] = v[i] * j;
			nw[nidx] = w[i] * j;		
		}
		
		if(m[i]) {
			nidx++;
			nv[nidx] = v[i] * m[i];
			nw[nidx] = w[i] * m[i];
		}
	}

	for(i = 1; i <= nidx; i++) {
		for(j = BW; j >= nw[i]; j--) {
			f[j] = max(f[j], f[j - nw[i]] + nv[i]);
		}
	}
	
    printf("%d", f[BW]);
    return 0;
}
