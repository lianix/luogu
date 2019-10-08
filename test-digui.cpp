#include <bits/stdc++.h>
using namespace std;

int append1(int n)
{
	int sum = 0;
	if (n == 1)
		return 1;

	for ( int i = 1; i <= n/2; i++)
		sum += append1(i);
	return sum + 1;		
	
}


int ans;
void append2(int n)
{
	ans++;
	
	if(n==1)
		return;
	
	for(int i = 1; i <=n/2; i++)
		append2(i);
}


void append3(int n, int *cnt)
{
	(*cnt)++;

	if (n == 1)
		return;
	
	for ( int i = 1; i <= n/2; i++)
		append3(i, cnt);
}


int main()
{
	printf("append1: %d\n", append1(6));
	
	append2(6);
	printf("append2: %d\n", ans);
	
	int cnt = 0;
	append3(6, &cnt);
	printf("append3: %d\n", cnt);
	
 } 
