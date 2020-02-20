#include <bits/stdc++.h>
using namespace std;

char tree[1048];
char str[1048];
int n, endidx;

void createRoot(int start, int end)
{
	int root;
	
	if(start == end)
		return;

	for(int i = start; i < end; i=i+2) {
		root = i / 2;
		if(tree[i] == tree[i+1]) {
			tree[root] = tree[i];
		} else {
			tree[root] = 'F';
		}	
	}
	
	createRoot(start / 2, end / 2);
}
 
void postTraverse(int idx)
{
	if(idx > endidx)
		return; 
	
	postTraverse(2 * idx);
	postTraverse(2 * idx + 1);
	printf("%c", tree[idx]);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	
	int start = pow(2, n);
	int end =  pow(2, n + 1) - 1;
	endidx = end;
	int idx = 0;
	
	for(int i = start; i <= end; i++) {
		if(str[idx++] == '0')
			tree[i] = 'B';
		else
			tree[i] = 'I';
	}
	
	createRoot(start, end);
	
	postTraverse(1);
	
	return 0;
} 
