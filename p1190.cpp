#include <bits/stdc++.h>
using namespace std;

int n, m;
int water[106], w, idx;

void insert(int w)
{
	int tmp, i;
	
	if(idx < m)
		idx++;

	tmp = water[idx] + w;
	for(i = idx; i>1; i--) {
		if(water[i - 1] < tmp)
			water[i] = water[i - 1];
		else
			break;
	}
	
	water[i] = tmp;	
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &w);
		insert(w);
	}
	
	printf("%d", water[1]);
	
	return 0;
}
