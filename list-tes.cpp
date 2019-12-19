#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
};

Node *mylist;
int len;

void init(Node **yourlist)
{
	Node *p, *s;
	int d;
	
	p = new Node; // 头结点 
	p->next = NULL;
	*yourlist = p;
	
	while(cin >> d) {
		s = new Node;
		s->data = d;
		s->next = NULL;
		p->next = s;
		p = s;
		len++;
	}		
}

void print(Node *yourlist)
{
	Node *p;
	
	p = yourlist;
	p = p->next; // 跳过头结点 
	cout <<"mylist:";
	while(p != NULL) {
		cout <<"-->" << p->data;
		p = p->next;
	}
	
	cout <<endl;	
}

int get(Node *yourlist, int idx)
{
	Node *p = yourlist;
	
	if(idx > len)
		return -1;
		
	while(idx--) {
		p = p->next;
	}
	
	return p->data;	
}

bool insert(Node *yourlist, int idx, int data)
{
	Node *p = yourlist->next;
	if(idx > len)
		return false;
	
	int i = 1;
	while(i < idx - 1) {
		p = p->next;
		i++;
	}
	
	Node *s = new Node;
	s->data = data;
	s->next = p->next;
	p->next = s;
	
	return true;	
}

int remove(Node *yourlist, int idx)
{
	Node *p = yourlist->next;
	
	if(idx > len)
		return false;
		
	int i = 1;
	while(i < idx - 1) {
		p = p->next;
		i++;
	}
	
	p->next = p->next->next;	
}

int main()
{
	init(&mylist);
	print(mylist);
	insert(mylist, 2, 5);
	print(mylist);
	remove(mylist, 3);
	print(mylist);
	
	return 0; 
}
