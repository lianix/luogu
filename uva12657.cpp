#include <bits/stdc++.h>
using namespace std;

//#define DEBUG

struct Node {
	int idx;
	Node *next, *prior;
};

Node node[100006];
int n, m, cmd, a, b, cnt;
bool reverse_flag;

void deleteNode(Node *x)
{
	x->prior->next = x->next;
	x->next->prior = x->prior;
}
 
void inline insertL(Node *x, Node *y)
{
	deleteNode(x);
	x->next = y;
	x->prior = y->prior;
	y->prior->next = x;
	y->prior = x;
} 

void inline insertR(Node *x, Node *y)
{
	deleteNode(x);
	x->prior = y;
	x->next = y->next;
	y->next->prior = x;
	y->next = x;
} 

void inline exchange(Node *x, Node *y)
{
	Node *front = x->prior;
	insertL(x,  y);
	insertR(y, front);
}

#if 0
void reverseNode()
{
	Node *x, *y, *tail;
	
	x = &node[0];
	y = tail = node[n+1].prior;
	
	while(y != &node[0]) {
		tail = tail->prior;
		x->next = y;
		y->prior = x;
		x = y;
		y = tail;
	}
	
	x->next = &node[n+1];
	node[n+1].prior = x;
}
#endif

void inline printL()
{
#ifdef DEBUG
	Node *x;
	x = node[0].next;
	printf("List:\n");
	while(x != &node[n+1]) {
		printf("<-->%d", x->idx);
		x = x->next;
		
	}
	printf("\n");
	
#endif
}

long long inline sum()
{
	Node *head, *tail, *x;
	long long total = 0;
	int index;
	if(reverse_flag) {
		head = &node[n+1];
		tail = &node[0];
		index = 1;
		x = head->prior;
		while(x != tail) {
			if(index & 1 == 1)
				total+= x->idx;
			x = x->prior;
			index++;
		}	
	} else {
		tail = &node[n+1];
		head = &node[0];
		index = 1;
		x = head->next;
		while(x != tail) {
			if(index & 1 == 1)
				total+= x->idx;
			x = x->next;
			index++;
		}		
	}
	
	return total;
}

int main()
{
	int i;
	
	while(cin >> n >> m) {
		cnt++;
		reverse_flag = false;
		for(i = 1; i <= n+2; i++) {
			node[i].idx = i;
			node[i-1].next = &node[i];
			node[i].prior = &node[i-1];
		}
	
	//	printL();
		for(int j = 0; j < m; j++) {
			scanf("%d", &cmd);
			switch(cmd) {
			case 1:
				scanf("%d %d", &a, &b);
				if(reverse_flag)
					insertR(&node[a], &node[b]);
				else
					insertL(&node[a], &node[b]);
				break;
				
			case 2:
				scanf("%d %d", &a, &b);
				if(reverse_flag)
					insertL(&node[a], &node[b]);
				else
					insertR(&node[a], &node[b]);	
				break;
	
			case 3:
				scanf("%d %d", &a, &b);
				exchange(&node[a], &node[b]);
				break;
	
			case 4:
				reverse_flag = ! reverse_flag;
				break;
			}
		//	printL();
		}
		
		printf("Case %d: %lld\n", cnt, sum() );
	}	
} 
