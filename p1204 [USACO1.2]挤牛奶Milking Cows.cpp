#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5006;
struct Tree {
	int start, end;
};

Tree t[MAXN];

int maxwork = 0,  maxfree = 0; 
int n;

bool cmp(Tree t1, Tree t2) 
{
	return t1.start < t2.start;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &t[i].start, &t[i].end);
	}
	
	sort(t+1, t+1+n, cmp);
	
	Tree tmpt = t[1];
	for(int i = 2; i <= n; i++) {
 		if(t[i].start <= tmpt.end) {
 			tmpt.end = max(t[i].end, tmpt.end);
		} else {
			maxwork = max(maxwork, tmpt.end - tmpt.start);
			maxfree = max(maxfree, t[i].start - tmpt.end);
			tmpt = t[i];
		}
 	}
 
 	maxwork = max(maxwork, tmpt.end - tmpt.start);
		
 	printf("%d %d", maxwork, maxfree);
 	
 	return 0;
 }
