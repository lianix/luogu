#include <bits/stdc++.h>
using namespace std;

int dn[62], dv[62];
int zhun, zhu[62], fu[62][62];
int f[32002], ans;
int n, m;

int main()
{
	int i, j, k;
	int v, p, q;
	
    scanf("%d %d",&n,&m);
    for(i = 1; i <= m; i++) {
		scanf("%d %d %d", &v, &p, &q);
		dn[i] = v;
		dv[i] = v * p;
		if(q) {
			fu[q][0]++;
			fu[q][fu[q][0]] = i;
		} else {
			zhun++;
			zhu[zhun] = i;
		}
	}
	
	for (i = 1; i <= zhun; i++) {
		int idx = zhu[i];
		for (j = n; j >= dn[i]; j--) {
			f[j] = max(f[j], f[j - dn[idx]] + dv[idx]);
			
			int fu1 = fu[idx][1];
			int fu2 = fu[idx][2];
		
			if (j >= dn[idx] + dn[fu1]) {
				f[j] = max(f[j], f[j - (dn[idx] + dn[fu1])] + 
					dv[idx] + dv[fu1]);
			}
				
			if (j >= dn[idx] + dn[fu2]) {
				f[j] = max(f[j], f[j - (dn[idx] + dn[fu2])] + 
					dv[idx] + dv[fu2]);
			}
		
			if (j >= dn[idx] + dn[fu1] + dn[fu2]) {
				f[j] = max(f[j],f[j - (dn[idx] + dn[fu1] + dn[fu2]) ] +
					dv[idx] + dv[fu1] + dv[fu2]);
			}
		}
	}
	
	printf("%d", f[n]);
	return 0;
}
