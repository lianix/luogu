#include <cstdio>
using namespace std;

int tree[10002]={0,};
int i, l, m, start, end;

int main(){
	scanf("%d %d", &l, &m);
	for(i=0; i<=l; i++){
		tree[i] = 1;
	}
	//
	for(i =0; i < m; i++)
	{
		scanf("%d %d", &start, &end);
		for(int j=start; j<=end; j++)
			tree[j] = 0;
	}
	return 0;
}
