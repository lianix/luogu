#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	Node *lchild, *rchild;
};

Node *tree;

char z[10], h[10];
int ztoh[10]; //中序遍历每个节点在后续中的位置 

void createmap(char *strz, char *strh)
{
	int len = strlen(z);
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(strh[j] == strz[i]) {
				ztoh[i] = j;
				break;
			}
		}
	}
}
 
Node *createroot(int zstart, int zend)
{
	if(zstart > zend)
		return NULL;

	Node *root = new Node;
	int maxj = ztoh[zstart], zi = zstart;
	for(int i = zstart; i <= zend; i++) {
		if(ztoh[i] > maxj) {
			maxj = ztoh[i];
			zi = i;
		}		
	}
	
	root->data = h[maxj];
	
	root->lchild = createroot(zstart, zi - 1);
	root->rchild = createroot(zi + 1, zend);
}

void pretraverse(Node *tree) 
{
	if(tree== NULL)
		return;
	
	printf("%c",tree->data);
	pretraverse(tree->lchild);
	pretraverse(tree->rchild);
}

int main()
{
	scanf("%s", z);
	scanf("%s", h);
	
	createmap(z, h);
	
	tree = createroot(0, strlen(z) - 1);
	
	pretraverse(tree);
	
	return 0;
} 
