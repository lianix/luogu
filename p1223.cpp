#include<bits/stdc++.h>
using namespace std;

struct water {
    int idx;
	int time;   
};
water w[1008];
double t;
int n;


bool compare(water w1 ,water w2) {
    return w1.time < w2.time;
}

int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&w[i].time);
        w[i].idx=i;
    }
    
    sort(w+1, w+n+1, compare);
    for(int i=1; i<=n; i++) {
    	printf("%d ", w[i].idx);
    	t+=w[i].time * (n- i);
	}
        
    printf("\n");
    printf("%.2f",t/n);
    
    return 0;
}
