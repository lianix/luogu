#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

int n, k;
int a[MAXN], amin[MAXN], amax[MAXN];
int ansmin[MAXN], ansmax[MAXN];

void min_q()
{	 
	int minh = 1, mint = 0;
	
	for(int i = 1; i <= n; i++) {
		if(amin[minh] <= i - k)
			minh++;
		while(mint >= minh && a[amin[mint]] > a[i])
			mint--;
		mint++;
		amin[mint] = i;
		
		if(i >= k)
			ansmin[i] = a[amin[minh]];
	}
}

void max_q()
{	 
	int maxh = 1, maxt = 0;
	
	for(int i = 1; i <= n; i++) {
		if(amax[maxh] <= i - k)
			maxh++;
		while(maxt >= maxh && a[amax[maxt]] < a[i])
			maxt--;
		maxt++;
		amax[maxt] = i;
		
		if(i >= k)
		ansmax[i] = a[amax[maxh]];
	}
}


int main()
{
	int i;
	
	scanf("%d %d", &n, &k);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	min_q();
	max_q();
	
	for(int i = k; i <= n; i++) {
		printf("%d ", ansmin[i]);
	}
	printf("\n");
	for(int i = k; i <= n; i++) {
		printf("%d ", ansmax[i]);
	}
	
	return 0;
}
