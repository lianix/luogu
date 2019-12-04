#include <bits/stdc++.h>
using namespace std;

//#define MYDEBUG
#ifdef MYDEBUG  
#define debug(...) printf(##__VA_ARGS__)  
#else  
#define debug(...)  
#endif 

char opt[10], opt2[10];
int a, b;

int n;
struct Block {
	int dest;
	vector<int> vec;
};

Block  block[30];

void moveback(int a)
{
	int ad, c;

	ad = block[a].dest;

	for(int i = block[ad].vec.size() - 1; i>=0; i--) {
		c = block[ad].vec[i];
		if(c == a)
			break;

		block[c].vec.push_back(c);
		block[c].dest = c;
		block[ad].vec.pop_back();
		debug("%d -> %d\n", c, c);
	}
}

void move(int a, int b)
{
	int i, idx, c;
	int ad;
	
	ad = block[a].dest;
	
	for(i = 0; i < block[ad].vec.size(); i++) {
		if(block[ad].vec[i] == a)
			break;
	}
	
	idx = i;
	for(; i < block[ad].vec.size(); i++) {
		c = block[ad].vec[i];
		block[b].vec.push_back(c);
		block[c].dest = b;
		debug("%d -> %d\n", c, b);
	}
	
	block[ad].vec.resize(idx);
}

int main()
{
	scanf("%d", &n);
	
	int i;
	for(i = 0; i < n; i++) {
		block[i].vec.push_back(i);
		block[i].dest = i;
	}
	
	while(1) {
		scanf("%s", opt);
		if(strcmp(opt, "quit") == 0)
			break;
			
		scanf("%d%s%d", &a, opt2, &b);
		debug("%s %d %s %d\n", opt, a, opt2, b);
		
		if(block[a].dest == block[b].dest)
			continue;
		if(strcmp(opt, "move") == 0) {
			if(strcmp(opt2, "onto") == 0) {
				moveback(a);
				moveback(b);
			} else {
				moveback(a);
				b = block[b].dest;
			}
		} else {
			if(strcmp(opt2, "onto") == 0) {
				moveback(b);
			} else {
				b = block[b].dest;
			}
		}
		move(a, b);
	}
	
	int j;
	for(i = 0; i < n; i++) {
		printf("%d:", i);
		for(j = 0; j < block[i].vec.size(); j++) {
			printf(" %d", block[i].vec[j]);
		}
		printf("\n");
	}
	
	return 0;
}
