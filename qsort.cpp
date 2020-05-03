#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf("%d: "format, __LINE__, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

int n;
long long a[1000008];

void qsort(int start, int end)
{
	int mid = a[(start + end) / 2];
	int left = start, right = end;
	int tmp;
	
	if(left >= right)
		return;
		
	while(left <= right) {
		while(a[left] < mid)
			left++;
		while(a[right] > mid)
			right--;
			
		if(left <= right) {
			tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
			left++;
			right--;
		}		
	}

	if(start < right)	
		qsort(start, right);
	if(left < end)
		qsort(left, end);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	qsort(0, n-1);
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}
