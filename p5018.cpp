#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	int lchild, rchild;
};

Node tree[10000002];

int n, maxn;


int cmptree(int origin, int reverse)
{
	int left, right, total;
	
	if(origin == -1 && reverse == -1)
		return 0;
	if(origin == -1 || reverse == -1)
		return -1;
	
	if(tree[origin].data != tree[reverse].data)		
		return -1;
	
	left = cmptree(tree[origin].lchild,
					tree[reverse].rchild);
	if(left == -1)
		return -1;
		
	right = cmptree(tree[origin].rchild,
					tree[reverse].lchild);
	if(right == -1)
		return -1;
	
	total = left + right + 2;

	return total;			
}

void findtree(int root) {
	int total;
	
	if(root == -1)
		return;

	total = cmptree(tree[root].lchild, tree[root].rchild);
	if(total == -1) {
		findtree(tree[root].lchild);
		findtree(tree[root].rchild);
	}
	else {
		total++;
		if(total > maxn)
			maxn = total;
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &tree[i].data);
	}

	for(i = 1; i <= n; i++) {
		scanf("%d %d", &tree[i].lchild,
			&tree[i].rchild);
	}
	
	findtree(1);
		
	printf("%d", maxn);
	
	return 0;
} 
