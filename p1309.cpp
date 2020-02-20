#include<bits/stdc++.h>
using namespace std;

struct Person {
	int power;
	int score;
	int idx;
};

Person p[200000 + 2];

int pp[200000 + 2];
int loser[100000 + 2];
int winner[100000 + 2];

int n, r, q;

bool cmp(int p1, int p2) 
{
	if(p[p1].score == p[p2].score)
		return p[p1].idx < p[p2].idx;
	return p[p1].score > p[p2].score;
}

void merge()
{
	int widx, lidx , i;
	
	widx = lidx = i = 1;
	while(widx <=n && lidx <=n){
		if(cmp(winner[widx], loser[lidx])) {
			pp[i++] = winner[widx++];
		} else {
			pp[i++] = loser[lidx++];
		}		
	}	
	
	while(widx<=n) {
		pp[i++] = winner[widx++];
	}
	
	while(lidx<=n) {
		pp[i++] = loser[lidx++];
	}
}

int main()
{
	int i;
	
	scanf("%d %d %d", &n, &r, &q);
    
    for(i = 1; i <= 2 * n; i++) {
    	scanf("%d", &p[i].score);
    	p[i].idx = i;
    	pp[i] = i;
	}
	
	for(i = 1; i <= 2 * n; i++) {
    	scanf("%d", &p[i].power);
	}
	
	sort(pp+1, pp+2*n+1, cmp);
	
	int pp1, pp2;
	while(r--) {
		for(i = 1; i <= n; i++) {
			pp1 = pp[2*i-1];
			pp2 = pp[2*i];
			if(p[pp1].power > p[pp2].power) {
				p[pp1].score++;
				winner[i] = pp1;
				loser[i] = pp2;
			} else {
				p[pp2].score++;
				winner[i] = pp2;
				loser[i] = pp1;
			}		
		}	
		merge();	
	}
	
	printf("%d", p[pp[q]].idx);
		
    return 0;
}
