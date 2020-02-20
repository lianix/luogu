#include<bits/stdc++.h>
using namespace std;

int n, f[40][40], root[40][40];

void print(int l,int r) {
    if(l > r)
		return ;
    
	printf("%d ", root[l][r]);
    
	print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}

int main() {
    int i;
    
	scanf("%d", &n);
    for(i = 1; i <= n; i++) {
		scanf("%d", &f[i][i]);
		root[i][i] = i;
		f[i][i-1] = 1; 
	}
	
    for(i = 2; i <= n; i++)
     for(int l = 1; l + i - 1 <= n; l++) {
        int r = l + i - 1;
        for(int k = l; k<= r; k++)
         if(f[l][r] < f[l][k-1] * f[k+1][r] + f[k][k]) {
            f[l][r] = f[l][k-1] * f[k+1][r] + f[k][k];
            root[l][r] = k;
         }
     }
     
    printf("%d\n",f[1][n]);
    print(1,n);
} 
