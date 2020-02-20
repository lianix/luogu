#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	int lchild, rchild;
};

Node tree[28];

int n, root = -1;
char str[4];

void preTraverse(int idx)
{
	if(idx == -1)
		return;
	
	printf("%c", 'a' + idx);
	preTraverse(tree[idx].lchild);
	preTraverse(tree[idx].rchild);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", str);
		int idx = str[0] - 'a';
		if(str[1] == '*') {
			tree[idx].lchild = -1;
		} else {
			tree[idx].lchild = str[1] - 'a';
		}
		
		if(str[2] == '*') {
			tree[idx].rchild = -1;
		} else {
			tree[idx].rchild = str[2] - 'a';
		}
		
		if(root == -1)
			root = idx;
		if(root == tree[idx].lchild ||
		   root == tree[idx].rchild)
		   	root = idx;
	}
	
	preTraverse(root);
	
	return 0;
} 
