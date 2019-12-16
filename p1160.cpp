#include <bits/stdc++.h>
using namespace std;

list <int> slist;
list <int> ::iterator sit[100006], it;
int n, m;

#define DEBUG
#ifdef DEBUG
void debug()
{
	list <int>::iterator it;
	printf("\ndebug:");
	for(it = slist.begin(); it != slist.end(); it++) {
		printf("-%d", *it);
	}
	printf("\n");
}
#endif

int main()
{
	scanf("%d", &n);
	
	slist.push_back(1);
	sit[1] = slist.begin();
	
	int idx, dir;
	for(int i = 2; i <= n; i++) {
		scanf("%d %d", &idx, &dir);
		if(dir == 0) {
			it = slist.insert(sit[idx], i);
		} else {
			it = slist.insert(++sit[idx], i);
		}
		sit[i] = it;
#ifdef DEBUG
		debug();
#endif
	}
		
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &idx);
		slist.erase(sit[idx]);
	}	
	
	for(it = slist.begin(); it != slist.end(); it++) {
		if(it != slist.begin())
			printf(" %d", *it);
		else
			printf("%d", *it);
	}
	printf("\n");	
		
	return 0;
}
