#include <bits/stdc++.h>
using namespace std;

char  a[500][500];
int   b[56][56];
int  m, n, width, length;
int x, y;

const char u[6][8] = {
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+.."
};

void draw(int x, int y)
{
	int i, j;
	for(i = 5; i >=0 ; i--)
		for(j = 0; j < 7; j++) {
			if(u[i][j] != '.')
				a[y-(5-i)][x+j] = u[i][j];
		}	
}

int main()
{
	int i, j;
	
	scanf("%d %d", &m, &n);
	
	for(i=0; i<m; i++)
		for(j=0; j<n; j++) {
			scanf("%d", &b[i][j]);
			width = max(width, b[i][j]*3+1 + 2*(m-i));
		}
	length = 4*n+1 + 2*m;

	for(i=0; i<m; i++)    
		for(j=0; j<n; j++)
		{
			x=2*(m-i-1)+4*j;
			y=width-2*(m-i-1) - 1;
            while(b[i][j]--) {
                draw(x,y);
                y-=3;
            }
        }
		
	for(i=0; i<width; i++) {
		for(j=0; j<length; j++) {
			if(a[i][j] == 0)
				printf(".");
			else
        		printf("%c", a[i][j]);
		}
         printf("\n"); 
	}
    
    return 0;
}
