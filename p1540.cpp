#include <bits/stdc++.h>
using namespace std;

int M, N;
int m[108];
int cnt;

int main()
{
	int a;
	int idx = 0;
	int i, j;

	scanf("%d %d", &M, &N);
	memset(m, -1, sizeof(m));
	for(i = 0; i < N; i++){
		scanf("%d", &a);
	
		for(j = 0; j< M; j++) {
			if(m[j] == a)
				break;
		}
		if(j==M){
			cnt++;
			m[idx] = a;
			idx++;
			if(idx == M)
				idx = 0;
		}
	}
	
	printf("%d", cnt);
	return 0;	
}
