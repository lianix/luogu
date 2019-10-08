#include <bits/stdc++.h>
using namespace std;

char p[108];
char maxp[108];
int m;
int maxid;

bool compare(char *p1, char *p2)
{
	int l1= strlen(p1);
	int l2= strlen(p2);
	if(l1 > l2)
		return true;
	if(l1 < l2)
		return false;
	
	if(strcmp(p1, p2) > 0)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d", &m);
	for(int i = 1; i <=m; i++) {
		scanf("%s", p);
		if(compare(p, maxp)) {
			maxid = i;
			strcpy(maxp, p);
		}				
	}
	
	printf("%d\n%s", maxid, maxp);
	
	return 0;
}
