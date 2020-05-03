#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 1;
int n;
int a[MAXN];
long long ans;

void merge(int arr[], int start, int mid, int end)
{
	int len = end - start + 1;
	int *tmp = new int[len];
	
	int ai = start;
	int bi = mid + 1;
	int ti = 0;
	
	while(ai <= mid && bi <=end) {
		if(arr[ai] <= arr[bi]) {
			tmp[ti++] = arr[ai++];
		} else {
			tmp[ti++] = arr[bi++];
			ans += mid - ai + 1;
		}		
	}
	
	while(ai <= mid)
		tmp[ti++] = arr[ai++];
	
	while(bi <= end)
		tmp[ti++] = arr[bi++];
	 
	for(int i = 0; i < len; i++) {
		arr[start + i] = tmp[i];
	}
	
	delete [] tmp;
}

void msort(int arr[], int start, int end)
{
	if(start >= end)
		return;
		
	int mid  = (start + end) / 2;
	
	msort(arr, start, mid);
	msort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	msort(a, 0, n-1);
	
	printf("%lld", ans);
	
	return 0;
}
