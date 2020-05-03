#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6 + 3;
const int MAXN = 2e5 + 2;

struct Node {
	int key;
	int num;
};

Node t[MOD];
int a[MAXN], n, c;

long long ans;

inline int hash1(int key)
{
	return abs(key) % MOD;
}

inline int hash2(int key)
{
	return 1 + (abs(key) % (MOD - 1));
}

int myfind(int key)
{
	int h;

	for(int i = 0; ; i++) {
		h = ((hash1(key)) + i * hash2(key)) % MOD;
		if(t[h].key == key)
			return h;
		if(t[h].num == 0)
			return h;
	}	
	
	return 0;
}

void myinsert(int key)
{
	int h = myfind(key);
	t[h].num++;
	t[h].key = key;		
}

int main()
{
    int i;
	
	scanf("%d %d", &n, &c);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		myinsert(a[i]);
	}
		
	for(i = 0; i < n; i++) {
		int h = myfind(a[i] - c);
		ans += t[h].num;
	}
		
	printf("%lld", ans);
}
