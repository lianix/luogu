#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...) 
#endif

struct Person{
	int idx;
	Person *next;
};

Person *cur, *pre;
int n, s;
Person p[70000];
char a[70000];

int main()
{
	int ret, i;
	while(scanf("%d %d", &n, &s)!=EOF) {
		memset(a, 'G', 2*n+1);
							
		for(i = 1; i <= 2*n; i++) {
			p[i].idx = i;
			p[i].next = &p[i+1];
			debug("-->%d", p[i].idx);
		} 
		p[2*n].next = &p[1];
		
		cur = &p[1];
		pre = &p[2*n];
		int m;
		debug("\nremove:\n");
		for(i = 1; i <= n; i++) {
			
			for(int m = 1; m < s; m++) {
				pre = pre->next;
			}
			
			cur = pre->next;
			a[cur->idx] = 'B';
			debug("-->%d", cur->idx);
			pre->next = cur->next;
			cur = cur->next;
		}
		
		for(i = 1; i <= 2 * n; i++) {
			printf("%c", a[i]);
			if(i % 50 == 0) {
				printf("\n");
			} 
		}
		printf("\n\n");
	}
	
	return 0;
}
