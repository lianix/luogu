#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202;
 
int n, a[MAXN];
int f[MAXN][MAXN], ans;
 
int main()
{
	int i, k, len;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[n+i] = a[i];
	}
			
	for(len = 2; len <= n; len++) // ���� 
		for(i = 1; i+len-1 < 2*n; i++) { // ��� 
			int ends = i + len - 1; //�յ� 
			for(k = i; k < ends; k++) { // �м��
				f[i][ends] = max(f[i][ends],
					f[i][k] + f[k+1][ends] + 
					a[i] * a[k+1] * a[ends+1]);
			}
		}

	for(i = 1; i <= n; i++)
		ans=max(ans,f[i][i+n-1]);
		
    printf("%d\n", ans);
}
