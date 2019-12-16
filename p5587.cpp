#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG  
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)  
#else  
#define debug(fmt, ...)  
#endif 

const int MAXL = 1e4 + 1;
const int MAXC = 1e5 + 2;
char a[MAXC];
char b[MAXC];
int T;
int cnt;
int correct;
double ans;

int readline(char str[], int start)
{
	char c;
	int idx = start;
	
	for(int i = 0; i < MAXC; i++) {
		c = getchar();
		if(c == 'E') {
			getchar(); //O
			getchar(); //F
			getchar(); //\n
			return 0;
		}
		else if(c == '<') {
			if(idx > start)
				idx--;
		}
		else {
			str[idx] = c;
			idx++;
			if(c == '\n') {
				return idx;
			}
		}
	}
		
	return 0;
}

int main()
{
	int i;
	int starta = 0;
	for(i = 0; i < MAXL; i++) {
		starta = readline(a, starta);
		if(starta == 0)
			break;
	}
	
	debug("got:\n");
	debug("%s", a);
	
	//ÊäÈë:
	int aidx = 0;
	int bidx;
	int endb;
	for(i = 0; i < MAXL; i++) {
		endb = readline(b, 0);
		if(endb == 0)
			break;
#ifdef DEBUG
		b[endb] = '\0';
		debug("got:\n%s", b);
#endif
		bidx = 0;	
		while(a[aidx] != '\n' &&
		      b[bidx] != '\n') {
			if(a[aidx] == b[bidx]) {
				correct++;
			} 
			aidx++;
			bidx++;
		}
		
		while(a[aidx] != '\n') {
			aidx++;
		}
		
		aidx++; // start next line
	}	
			
			
	scanf("%d", &T);
	
	ans = 60.0 * correct  / T;
	ans += 0.5;
	
	printf("%d", (int)ans);
	
	return 0;
}
