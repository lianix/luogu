#include <bits/stdc++.h>
using namespace std;

const int MAXN = 106;
char astr[MAXN], bstr[MAXN];
int an, a[MAXN];
int bn, b[MAXN];
int f[MAXN][MAXN];

int gmap[5][5]=
{
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};

int chartoint(char c)
{
    switch(c)
	{
		case 'A': 
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
	} 
	return 4;
}

int main()
{
	int t,i,j;
	scanf("%d %s", &an, astr);
	scanf("%d %s", &bn, bstr);
	
	for(i = 1; i <= an; i++)
		a[i]=chartoint(astr[i-1]);
	for(i = 1; i <= bn; i++)
		b[i]=chartoint(bstr[i-1]);
	
	memset(f, 0xf0, sizeof(f));
	
	f[0][0] = 0;
	for(i = 1; i <= an; i++)
		f[i][0] = f[i-1][0] + gmap[a[i]][4];
	for(i = 1; i <= bn; i++)
		f[0][i] = f[0][i-1]+ gmap[4][b[i]];
		
	for(i = 1; i <= an; i++)
		for(j = 1; j <= bn; j++) {
		f[i][j] = max(f[i][j], f[i][j-1]+ gmap[4][b[j]]);
		f[i][j] = max(f[i][j], f[i-1][j] + gmap[a[i]][4]);
		f[i][j] = max(f[i][j], f[i-1][j-1] + gmap[a[i]][b[j]]);
	}
	
	printf("%d\n",f[an][bn]);
	
	return 0;
}
