#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

char b[5000][5000];
char a[2][5] = {
" /\\ ",
"/__\\",
};

int alen = 4;
int ah = 2;

#define len(num) (alen * (1 <<((num) - 1)))
#define h(num) (ah * (1 <<(num) - 1))

void drawa(int x, int y, int num)
{
	int xi, yi;
	
	if(num == 1) {
		for(xi = 1; xi>= 0; xi--)
			for(yi = 0; yi <= 3; yi++)
				b[x-1+xi][y+yi] = a[xi][yi];
		return;
	}
	
	drawa(x, y, num - 1);
	drawa(x, y + len(num - 1), num - 1);
	drawa(x - h(num - 1), y + len(num - 1) / 2, num - 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	
	memset(b, ' ', sizeof(b)); 
	
	drawa(h(n), 0, n);
		
	for(int i = 1; i <= h(n); i++) {
		for(int j = 0; j < len(n); j++)
			printf("%c", b[i][j]);
		printf("\n");	
	}
		
	return 0;
}
