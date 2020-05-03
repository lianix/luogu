#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf("%d: "format, __LINE__, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

int n;
int a[1000008];

void merge(int arr[], int start, int mid, int end)
{
	int len = end - start + 1;
	int *tmp = new int[len];
	
	int ai = start;
	int bi = mid + 1;
	int ti = 0;
	
	while(ai <= mid && bi <=end) {
		if(a[ai] <= a[bi]) {
			tmp[ti++] = arr[ai++];
		} else {
			tmp[ti++] = arr[bi++];
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
	
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	
	return 0;
}
