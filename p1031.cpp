#include <bits/stdc++.h>
using namespace std;

int n;
int a[108];
int total, avg,  ans;

int main()
{
	int left, right;
	
	scanf("%d", &n);
	for(left = 0; left < n; left++)	{
		scanf("%d", &a[left]);
		total += a[left];
	}

	avg = total / n;
	left = 0;
	right = n - 1;
	while(1) {
		// left
		if(left == right)
			break;
			
		if(left + 1 == right)
		{
			if (a[left] != avg)
				ans++;
			break;
		}
		
		if(a[left] > avg) {
			a[left + 1] += a[left] - avg;
			a[left] = avg;
			ans++;
		} else if(a[left] < avg) {
			a[left + 1] -= avg - a[left];
			a[left] = avg;
			ans++; 
		}
		left++;
		
		if(a[right] > avg) {
			a[right -1] += a[right] -avg;
			a[right] = avg;
			ans++;
		} else if(a[right] < avg) {
			a[right - 1] -= avg - a[right];
			a[right] = avg;
			ans++; 
		}
		right--;
		
	}
	
	printf("%d", ans);
	return 0;
}
