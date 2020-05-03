#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 2;

struct Ship {
	int start;
	int end; 
};

Ship s[MAXN];

bool cmp(Ship s1, Ship s2) {
	return s1.start < s2.start;
}

int n, ans;

int main()
{
	int i;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%d %d", &s[i].start, &s[i].end);
	}
		
	sort(s, s+n, cmp);
	
	int start = s[0].start;
	int end = s[0].end;
	for(i = 1; i < n; i++) {
		if(s[i].start > end) {
			ans += abs(end - start);
			start = s[i].start;
			end = s[i].end;
		} else {
			end = max(end, s[i].end);
		}	
	}
	
	ans += abs(end - start);
						
	printf("%d", ans);

	return 0;
}
