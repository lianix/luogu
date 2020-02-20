#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10006;

struct Task {
	int start;
	int end;
};
Task a[MAXN];

int n, k, sums[MAXN], f[MAXN], cnt = 1;

bool cmp(Task a1, Task a2)
{
	return a1.start > a2.start;
}

int main() {
	int i, j; 
    scanf("%d %d",&n, &k);
    for(i = 1; i <= k; i++)  {
        scanf("%d %d",&a[i].start, &a[i].end);
        sums[a[i].start]++; 
    }
    sort(a + 1, a + k + 1, cmp);
    
    for(i = n; i >= 1; i--){ 
        if(sums[i] == 0)
			f[i] = f[i + 1] + 1;
        else {
            for(j = 1; j <= sums[i]; j++){
                f[i] = max(f[i], f[i + a[cnt].end]);
                cnt++;
            }
        } 
    }
    printf("%d\n",f[1]);
    return 0;
}
