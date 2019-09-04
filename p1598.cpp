#include <cstdio>
#include <cstring>
using namespace std;

int c[26] = {0,};
char x;
char p[400][53];
int max=0;

int main()
{
	for(int i=0; i < 4; i++){
		while(1) {
			x = getchar();
			if(x == EOF || x=='\n')
				break;
			if(x>='A' && x <='Z' ) {
				x= x- 'A';
				c[x]++;
			}	
		}
	}
	
	for(int i =0; i < 26; i++) {
		if(max < c[i])
			max = c[i];
	}
			
	for(int i=0; i <=50; i++) {
		for(int j = 0 ; j <= max; j++) {
			p[j][i] = ' ';
		}
		
		if (i%2 == 0) {
			for(int j = 1 ; j <= c[i/2]; j++) {
				p[j][i] = '*';
			}
			p[0][i] = 'A' + i / 2;
		
	   	
		}
	}
	
	for(int j=max; j>=1 ; j--) {
		int flag = 0;
		for(int i =51; i>=0; i--) {
			if (p[j][i] != '*') {
					p[j][i] = '\0';
			} else {
				break;
			}
		}
	}
	
	p[0][51] = '\0';		
			
	for(int j=max; j>=0 ; j--) {
		printf("%s\n", p[j]);
	}
	
	return 0;
}

