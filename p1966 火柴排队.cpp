#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
const int MOD = 99999997;

struct Huocai {
	long long h;
	int idx; 
};

Huocai a[MAXN], b[MAXN];
int c[MAXN], n;
long long ans;

bool cmp(Huocai &a1, Huocai &a2)
{
	return a1.h < a2.h;
}

///////ÄæÐò¶Ô////
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
			ans %= MOD;
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
////////////

int main()
{
	int i;
	
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++) {
		scanf("%lld", &a[i].h);
		a[i].idx = i;	
	}    
	
	for(i = 1; i <= n; i++) {
		scanf("%lld", &b[i].h);
		b[i].idx = i;	
	}
	
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+n+1, cmp);
	 
	for(i = 1; i <= n; i++)
		c[b[i].idx] = a[i].idx;
		
	
	msort(c, 1, n); 
	
	printf("%lld", ans);
	
	return 0;
}
