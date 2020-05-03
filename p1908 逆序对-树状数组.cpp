#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+2;
int n;
long long ans;

struct A {
	int data;
	int idx;
};

A a[MAXN];
int b[MAXN], c[MAXN];

bool cmp(A &a1, A &a2)
{
	if(a1.data == a2.data)
		return a1.idx < a2.idx;
	
    return a1.data < a2.data;
}

int lowbit(int x)
{
	return x & (-x);
}

void add(int i, int x)
{
	while(i <= n) {
		c[i] += x;
		i += lowbit(i);
	}
}

int sum(int i)
{
    int ans = 0;
    while(i != 0) {
        ans += c[i];
        i -= lowbit(i);
    }
    return ans;
}


int main(void)
{
    int i;
    
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
    	scanf("%d", &a[i].data);
    	a[i].idx = i;
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(i = 1; i <= n; i++)
    	b[a[i].idx ]= i;
        
	for( i = 1; i <= n; i++) {
		add(b[i], 1);
		ans += i - sum(b[i]);
	}
	
	printf("%lld", ans);
}

