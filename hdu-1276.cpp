#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...) 
#endif

struct Soldiers {
	int idx;
	Soldiers *next;
};

Soldiers *p, *head, *cur;
int n, num;

void findsoldiers(int m)
{
	cur = head;
	
	int i;
	for(i = 1; i <= m; i++) {
		p = new Soldiers;
		p->idx = i;
		p->next = NULL;
		cur->next = p;
		cur = p;
	}
	
	int remain = m;
	while(remain > 3) {
		cur = head->next;
		while( cur != NULL && cur->next != NULL) {
			p = cur->next;
			cur->next = p->next;
			cur = p->next;
			debug("remove: %d\n", p->idx);
			delete p;
			remain--;
		}
		
		if(remain <= 3)
			break;
			
		cur = head->next;
		while( cur != NULL &&
			cur->next != NULL && 
			cur->next->next !=NULL) {
			p = cur->next->next;
			cur->next->next = p->next;
			cur = p->next;
			debug("remove: %d\n", p->idx);
			delete p;
			remain--;
		}
	}
	
	cur = head->next;
	while(cur) {
		if (cur != head->next)
			printf(" ");
		printf("%d", cur->idx);
		p = cur;
		cur = cur->next;
		delete p;
	}
	
	printf("\n");
}

int main()
{
	int i;
	
	head = new Soldiers;
	head->next = NULL;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		findsoldiers(num);
	}
	
	return 0;
}
