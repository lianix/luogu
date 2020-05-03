#include<bits/stdc++.h>
using namespace std;

const int MAXN =1e5+2;
int n, a[MAXN];
int minscore = MAXN;
double sum = 0.0, max_average = 0.0;
int k[MAXN];
int kidx;

int main()
{
	int i;
	scanf("%d", &n);
	
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	double average; 
	for(i = n; i > 1; i--) {
		sum += a[i];
		minscore = min(minscore, a[i]);
		if(i <= n-1) {
			average = (sum - minscore) / (n - i);
			if(abs(average - max_average) < 0.001) {
				kidx++;
				k[kidx] = i - 1;
			} else if ( average > max_average) {
				kidx = 1;
				k[kidx] = i - 1;
				max_average = average;
			}
		}
	}
	
	for(i = kidx; i >= 1; i--)
		printf("%d\n", k[i]);
    
	return 0;
}
