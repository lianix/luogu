#include <bits/stdc++.h>
using namespace std;

const int maxn=100008;
int n, now, sum;
long long a[maxn], f[maxn];

int searchp(int k, int left, int right)
{
	int mid;
	
	while(left < right)
	{
		mid = (left + right) / 2;
		if(k >= f[mid]) 
			left = mid + 1;
		else
			right = mid;
	}
	
	return left;
}

int main()
{
    int i;
    
	scanf("%d", &n);
    
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);

    for(i = 0; i < n; i++)
    {
		if(f[now] < a[i]) {
			now++;
			f[now] = a[i];
		} else {
			int cur = searchp(a[i], 0, now + 1);
			f[cur] = a[i];
			sum++;
		}
    }
    
    printf("%d\n", sum);
    return 0;
}
