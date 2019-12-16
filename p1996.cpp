#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG  
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)  
#else  
#define debug(fmt, ...)  
#endif 

struct node {
	int  id;
	node *next;
}; 

node *head;
node *tail;
int n, m;
 
int main()
{
	struct node *p;
	int i;
	
	cin >> n >> m;
	for(i = 1; i <=n; i++) {
		p = new node;
		p->id = i;
		if(head == NULL) {
			tail = head = p;
			p->next = head;
		} else {
			p->next = tail->next;
			tail->next = p;
			tail = p;
		}
	}
	
	p = head;
	if(p == NULL) {
		return 0;
	}
	
	int cnt = 1;
	while(p->next != p) {
		if(cnt >= m - 1) {
			printf("%d ", p->next->id);
			p->next = p->next->next;
			p = p->next;
			cnt = 1;
		} else {
			cnt++;
			p = p->next;
		}
	}
	
	printf("%d ", p->id);
	
	return 0;
}
