#include<bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug(format, ...)
#endif

int k, x, y, n;

void lay_carpet(int x, int y, int sx, int sy, int len)
{
	if (len == 1)
		return;
		
	int small_len = len / 2;
	
	//
	//  1  |  2
	// --  -  --
	//  3  | 4
	int x1 = sx+small_len-1,  y1 = sy+small_len-1;
	int x2 = sx+small_len-1,  y2 = sy+small_len;
	int x3 = sx+small_len,  y3 = sy+small_len-1;
	int x4 = sx+small_len,  y4 = sy+small_len;
	
	if (x <= x1 && y <= y1) { 
		printf("%d %d %d\n", x4, y4, 1);
		lay_carpet(x,  y,  sx, sy, small_len);
        lay_carpet(x2, y2, sx, y2, small_len);
        lay_carpet(x3, y3, x3, sy, small_len);
        lay_carpet(x4, y4, x4, y4, small_len);
	}
	
	else if (x <= x2 && y >= y2) {
		printf("%d %d %d\n", x3,  y3, 2);
		lay_carpet(x1, y1, sx, sy, small_len);
        lay_carpet(x,   y, sx, y2, small_len);
        lay_carpet(x3, y3, x3, sy, small_len);
        lay_carpet(x4, y4, x4, y4, small_len);
	}
	
	else if (x >= x3 && y <= y3) {
		printf("%d %d %d\n", x2,  y2, 3);
		lay_carpet(x1, y1, sx, sy, small_len);
        lay_carpet(x2, y2, sx, y2, small_len);
        lay_carpet(x,   y, x3, sy, small_len);
        lay_carpet(x4, y4, x4, y4, small_len);
	}
	
	if (x >= x4 && y >= y2) {
		printf("%d %d %d\n", x1,  y1, 4);
		lay_carpet(x1, y1, sx, sy, small_len);
        lay_carpet(x2, y2, sx, y2, small_len);
        lay_carpet(x3, y3, x3, sy, small_len);
        lay_carpet(x,  y,  x4, y4, small_len);
	}
		

			
} 

int main()
{
    scanf("%d %d %d", &k, &x, &y);
    n = 1 << k;
    
	lay_carpet(x, y, 1, 1, n);
	
#ifdef DEBUG
	debug("carpet:\n");
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <=n; j++)
			debug("%d ", a[i][j]);
		debug("\n");
	} 
#endif

	return 0;
}
