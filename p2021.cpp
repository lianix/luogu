#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...) 
#endif

struct Node {
	int idx;
	Node *next;
};

int a[1000002];
int b[1000002];

Node *p, *head, *tail;
int n;

int main()
{
	int i;
	cin >> n;
	p = new Node;
	head = tail = p;
	p->idx = 1; 
	for(i = 2; i <= n; i++) {
		p = new Node;
		p->idx = i;
		tail->next = p;
		tail = p;
	}
	
	for(i = 1; i <= n; i++) {
		tail->next = head;
		tail = head;
		a[i] = head->next->idx;
		head =  head->next->next;
		debug("%d ", a[i]);
	}
	
	for(i = 1; i <= n; i++) {
		b[a[i]] = i;
	}
	
	for(i = 1; i <= n; i++) {
		printf("%d ", b[i]);
	}
	
	return 0;
}
