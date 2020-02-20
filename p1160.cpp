#include <bits/stdc++.h>
using namespace std;

list <int> slist;
list <int> ::iterator sit[100006], it;
int a[100006];
int n, m;

//#define DEBUG
#ifdef DEBUG
void debug()
{
	list <int>::iterator it;
	printf("\ndebug:");
	for(it = slist.begin(); it != slist.end(); it++) {
		printf("<-->%d", *it);
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
			it = sit[idx];
			it++;
			it = slist.insert(it, i);
		}
		sit[i] = it;
#ifdef DEBUG
		debug();
#endif
	}
		
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		scanf("%d", &idx);
		if(a[idx] == 0)
			slist.erase(sit[idx]);
		a[idx] = 1;
	}	

	/*
	for(int i = 0; i < m; i++) {
		scanf("%d", &idx);
		it = find(slist.begin(), slist.end(), idx);
		if(it != slist.end())
			slist.erase(it);
	}	
	*/
	for(it = slist.begin(); it != slist.end(); it++) {
		if(it != slist.begin())
			printf(" %d", *it);
		else
			printf("%d", *it);
	}
	printf("\n");	
		
	return 0;
}
