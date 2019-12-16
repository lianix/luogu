#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG  
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)  
#else  
#define debug(fmt, ...)  
#endif 

char opt[10], opt2[10];
int a, b;
int n;

vector<int> block[30];
int	dest[30];
int high[30];
 
void moveback(int a)
{
	int d, h, c, i, len;

	d = dest[a];
	h = high[a];
	len = block[d].size();
	for(i = h + 1; i < len; i++) {
		c = block[d][i];

		high[c] = block[c].size();
		dest[c] = c;
		block[c].push_back(c);
		debug("%d -> %d\n", c, c);
	}
	
	block[d].resize(h + 1);
}

void move(int a, int b)
{
	int i, h, c;
	int d, len;

	d = dest[a];
	h = high[a];
	len = block[d].size();
	b = dest[b];
	
	for(i = h;	i < len; i++) {
		c = block[d][i];
		
		high[c] = block[b].size();
		dest[c] = b;
		block[b].push_back(c);
		debug("%d -> %d\n", c,                                                                                                         b);
	}
	
	block[d].resize(h);
}

int main()
{
	scanf("%d", &n);
	
	int i;
	for(i = 0; i < n; i++) {
		block[i].push_back(i);
		dest[i] = i;
		high[i] = 0;
	}
	
	while(1) {
		scanf("%s", opt);
		if(strcmp(opt, "quit") == 0)
			break;
			
		scanf("%d %s %d", &a, opt2, &b);
		debug("%s %d %s %d\n", opt, a, opt2, b);
		
		if(dest[a] == dest[b])
			continue;

		if(strcmp(opt, "move") == 0) {
			moveback(a);
			if(strcmp(opt2, "onto") == 0) {
				moveback(b);
			} else {
				//b = dest[b];
			}
		} else {
			if(strcmp(opt2, "onto") == 0) {
				moveback(b);
			} else {
				//b = dest[b];
			}
		}
		move(a, b);
	}
	
	int j;
	for(i = 0; i < n; i++) {
		printf("%d:", i);
		for(j = 0; j < block[i].size(); j++) {
			printf(" %d", block[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
