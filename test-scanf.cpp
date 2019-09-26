#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	char a[10]; 
	char  b[10];
	char c[10];
	char d[10];
	string s;
	char x;
	int ret;
	//int a[6] = {10, 20, 30, 40, 50};
	//getline(cin, s);
	
	//for(int i =0; i <= 6; i++) {
	//	printf("%d \n", a[i]);
	//}
	
	//	scanf("%[^\n]%*c", a);
	scanf("%[^\n]", a);
	//getchar();
	ret = 	scanf("%c", &x);
	printf("%c %d ret=%d\n", x, x, ret);
	
		ret = 	scanf("%c", &x);
	printf("%c %d ret=%d\n", x, x, ret);
	
		ret = 	scanf("%c", &x);
	printf("%c %d ret=%d\n", x, x, ret);
	
	scanf("%[^\n]", b);
	

	/*
	x = 12;
	for(int i =0; i < 10; i++) {
		
		if(scanf(" %c", &x) == EOF || x=='\n')
			break;
		printf("%c", x);
	}
		
*/
	
	printf("%s@@%s@@\n", a, b);
}
