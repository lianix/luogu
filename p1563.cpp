#include <bits/stdc++.h>
using namespace std;

int n,m;
char toy[100008][12];
int a[100008];

int main()
{
	int i;
	int d, s;

	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d %s", &a[i], toy[i]);
	}
	
	int idx = 0;
	int flag = 1; //ÄæÊ±Õë+ 1£» Ë³Ê±Õë -1 - 
	for(i=0; i < m; i++)
	{
		scanf("%d %d", &d, &s);
		if (a[idx] == 0) {
			if(d == 0){
				flag = -1;
			} else {
				flag = 1;
			}
		} else {
			if(d == 0){
				flag = 1; 
			} else {
				flag = -1; 
			}
		}
		
		idx = (idx + flag * s + n)%n; 	
	}
	
	printf("%s", toy[idx]);
	return 0;
}
