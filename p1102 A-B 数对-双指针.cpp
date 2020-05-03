#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 2;
int a[MAXN], n, c;
long long ans;

void find(int k, int left, int right)
{
	if(left > right)
		return;
	
	if((a[right] - a[k]) < c )
		return;
	
	if((a[left] - a[k]) > c )
		return;
		
	int mid = (left + right) >> 1;

	if(a[mid] - a[k] > c)
		find(k, left, mid-1);
	else if(a[mid] - a[k] < c)
		find(k, mid + 1, right);
	else {
		ans++;
		for(int i = mid + 1; i <= right; i++) {
			if(a[i] == a[mid])
				ans++;
			if(a[i] > a[mid])
				break;	
		}
		
		for(int i = mid-1; i >= left; i--) {
			if(a[i] == a[mid])
				ans++;
			if(a[i] < a[mid])
				break;			
		}
	}
}

int main()
{
	int i;
	
	scanf("%d %d", &n, &c);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
		
	sort(a, a+n);
	
	int p1=0, p2 = 0;
	for(i = 0; i < n; i++) {
		while(p1 < n && (a[p1] - a[i] <= c))
			p1++;
		while(p2 < n && (a[p2] - a[i] < c))
			p2++;
			
		if(a[p2] - a[i] == c &&
		   a[p1 - 1] - a[i] == c &&
		   p1 > 0)
				ans += p1 - p2;
	}
						
	printf("%lld", ans);

	return 0;
}
