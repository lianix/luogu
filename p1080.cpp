#include <bits/stdc++.h>
using namespace std;

int n;
struct person {
	int left;
	int right;
	int lr;
};

person p[10008];
bool compare(person p1, person p2)
{
	return p1.lr < p2.lr;
}


int total[1000000]={0, 1,};
int len = 1;
int coin[1000000]= {0}, lc;
int cmax[1000000], lmax;

const int jinzhi = 10;

void multiply(int m)
{
	int idx;
	int x = 0;
	for(idx = 1; idx <= len; idx++) {
		total[idx] = total[idx] * m + x;
		x = total[idx] / jinzhi;
		total[idx] %= jinzhi;
	}
	
	while(x) {
		len++;
		total[len] = x % jinzhi;
		x /= jinzhi;
	}	
}

void div(int k)
{
	int idx;
	int x = 0;
	
	memset(coin, 0, sizeof(coin));
	for(idx = len; idx>=1; idx--) {
		coin[idx] = (x * jinzhi + total[idx]) / k;
		x = (x * jinzhi + total[idx]) % k;		
	}
	
	lc = len;
	while(coin[lc] == 0) {
		if(lc == 1)
			break;
		lc--;
	}
}

void cmpmax()
{
	int i;
	if(lc < lmax) 
		return;
		
	if(lc == lmax) {
		for(i = lmax; i >= 1; i--) {
			if(cmax[i] > coin[i])
				return;
			if(cmax[i] < coin[i]) 
				break; 	
		}
			
	}	
		
	for(i = 1; i<=lc; i++) {
		cmax[i] = coin[i];
	}
	lmax = lc;
}

int main()
{
//	freopen("coin.in", "r", stdin);
//	freopen("coin.out", "w", stdout); 
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		scanf("%d %d", &p[i].left, &p[i].right);
		p[i].lr = p[i].left * p[i].right;
	}
	
	sort(p+1, p+n+1, compare);

	for(int i = 1; i <= n; i++) {
		 multiply(p[i-1].left);
		 div(p[i].right);
		 cmpmax();
	}	
	
		
	while(lmax>=1){
		printf("%d", cmax[lmax]);
		lmax--;
	}
	
	return 0;
}
