#include <bits/stdc++.h>
using namespace std;

char str[22][30];
char *p[22];
int n;

bool compare(char *x, char *y)
{
	char *tx = x, *ty=y;
	while(*tx!='\0' &&  *ty!='\0') {
		if(*tx > *ty)
			return true;
		else if(*tx < *ty)
			return false;
		else {
			tx++;
			ty++;
		}
	}
	
	if(*tx == '\0') {
		if(*ty == 0)
			return true;
		return compare(x, ty);		
	} else {
		return compare(tx, y);	
	}		
}

int main()
{
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", str[i]);
		p[i] = str[i];
	} 
	
	sort(p, p+n, compare);
	
	for(i = 0; i < n; i++) {
		printf("%s", p[i]);
	} 
	
	return 0;
}
