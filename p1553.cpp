#include <cstdio>
#include <cstring>
using namespace std;
char a[25];
int key, flag, i, len, start;

enum {
	ISINT,
	ISFLOAT,
	ISPRESENT,
	ISFENSHU,
};

//m<->n
int reverse(int m, int n)
{
//	printf("reverse %d %d\n", m, n);
	int tmp;
	while(m<n)
	{
		tmp = a[m];
		a[m] = a[n];
		a[n] = tmp;
		m++;
		n--;
	}
}

int main()
{
	scanf("%s", a);
	//printf("%s", a);
	//check type
	flag = ISINT;
	key = strlen(a);
	for(i = 0; i < key; i++)
	{
		if(a[i] == '.'){
			flag = ISFLOAT;
			key = i;			
		}
		if(a[i] == '%'){
			flag = ISPRESENT;
			key = i;		
		}
		if(a[i] == '/'){
			flag = ISFENSHU;
			key = i;		
		}
	}
	
//	printf("flag=%d key=%d %c\n", flag, key, a[key]);
	
	reverse(0, key -1);
	if (flag != ISINT)
		reverse(key+1, strlen(a) -1);
	
	len = strlen(a) -1 ;
	while(len) {
		if(a[len] == '0')
			len--;
		else
			break;
	}
	
	if (len < 0) {
		printf("%c", a[0]);
		return 0;
	}
	
	if(a[len] == '.')
		len++;
	
	for(i =0; i < key; i++)
	{
		if(a[i] == '0' && (start == 0)) {
			continue;
		}
		
		start = 1;
		printf("%c", a[i]);
	}
	
	if(start==0)
		printf("%c", '0');
		
	if(flag == ISINT)
		return 0;
		
	if(flag == ISPRESENT) {
		printf("%c", a[key]);
		return 0;
	}
	
	if(flag == ISFLOAT) {
		for(i = key; i <=len; i++)
		{
			printf("%c", a[i]);
		}
		return 0;
	}
	
	if(flag == ISFENSHU) {
		printf("%c", a[key]);
		start = 0;
		for(i = key + 1 ; i <=len; i++)
		{
			if(a[i] == '0' && (start == 0)) {
				continue;
			}
		
			start = 1;
			printf("%c", a[i]);
		}
		return 0;
	}
	
	return 0;
}
