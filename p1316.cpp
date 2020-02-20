#include<bits/stdc++.h>
using namespace std;


int x[1000006];
int a, b;

bool isOk(int dist)
{
	int cur = x[0];
	int num = 1;

    for(int i = 1; i < a; i++) {
        if((x[i] - cur) >= dist) {
        	cur = x[i];
        	num++;
		}
    }
    
    return num >= b;
}

int main()
{
    scanf("%d %d", &a, &b);
    
    for(int i = 0; i < a; i++) {
    	scanf("%d", &x[i]);
	}
	sort(x, x+a);
	
	int low = 0, high = x[a-1] - x[0];
	while(low <= high)
    {
		int mid = (low + high) / 2;
        if (isOk(mid)) {
        	low = mid + 1;	
		} else {
			high = mid - 1;
		}		
    }
    
    printf("%d", high);
    
    return 0;
}
