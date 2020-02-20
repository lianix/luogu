#include <bits/stdc++.h>
using namespace std;

struct stick{
	int len;
	int w;
};

stick s[5002];
int used[5002];
int n;
int t;

bool comlen(stick s1, stick s2) 
{
	return s1.len > s2.len;
}

int main()
{
	int i;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &s[i].len, &s[i].w);
	}
	
	sort(s, s+n, comlen);

	for(i = 0; i < n; i++) {
		if(used[i] == 1)
			continue;
		
		t++;
		int tw = s[i].w;
		for(int j = i+1; j < n; j++) {
			if(used[j] == 1)
				continue;
				
			if(s[j].w <= tw) {
				used[j] = 1;
				tw = s[j].w;
			}
		}
	}
	
	printf("%d\n", t);
	return 0;
}
