#include <bits/stdc++.h>
using namespace std;

int score[5][5] = {
{0,0,1,1,0},
{1,0,0,1,0},
{0,1,0,0,1},
{0,0,1,0,1},
{1,1,0,0,0}
};

int a[208],b[208];
int n, an, bn;
int sa, sb;

int main()
{
	int i;
	scanf("%d %d %d", &n, &an, &bn);
	for(i = 0; i < an; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < bn; i++)
		scanf("%d", &b[i]);	
	
	int ai = 0, bi = 0;
	for(i =0; i <n; i++) {
		sa += score[a[ai]][b[bi]];
		sb += score[b[bi]][a[ai]];
		ai =(ai + 1) %an;
		bi = (bi + 1) %bn;
	}
	printf("%d %d", sa, sb);
	return 0;
}

