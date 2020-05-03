#include <bits/stdc++.h>
using namespace std;

const int MAXN = 106;
struct Node {
	int y;
	int x1, x2;
};
Node a[MAXN];

int n, ans;

bool cmp(Node a1, Node a2) 
{
	if(a1.y == a2.y) {
		return a1.x1 < a2.x1;
	}
	
	return a1.y > a2.y;
}

int getx1(int i)
{
	for(int k = i+1; k <= n; k++) {
		if(a[i].y == a[k].y)
			continue;
		if(a[k].x1 <= a[i].x1 && a[k].x2 > a[i].x1) {
			return a[i].y - a[k].y;
		}
			
	}
	
	return a[i].y;
}

int getx2(int i)
{	
	for(int k = i+1; k <= n; k++) {
		if(a[i].y == a[k].y)
			continue;
		if(a[k].x1 < a[i].x2 && a[k].x2 >= a[i].x2) {
			return a[i].y - a[k].y;
		}
			
	}
	
	return a[i].y;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i].y, &a[i].x1, &a[i].x2);
	}
	
	sort(a+1, a+1+n, cmp);

	for(i = 1; i <= n; i++) {
		ans += getx1(i);
		ans += getx2(i);
	}
 
 	printf("%d", ans);
 	
 	return 0;
 }
