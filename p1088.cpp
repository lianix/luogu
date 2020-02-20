#include<bits/stdc++.h>
using namespace std;

int a[10006], n, m;

int main(){
	int i;
	
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
	}
	
    while(m--) 
		next_permutation(a, a + n);
		
    for(i = 0; i < n; i++) {
    	printf("%d ", a[i]);
	}
	      
    return 0;
}
