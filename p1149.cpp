#include <cstdio>
using namespace std;

#define MAX 20000
int a[MAX]= {6, 2, 5, 5, 4, 5, 6, 3, 7, 6,};
int n, cnt = 0;

int main()
{
	scanf("%d", &n);
	
	for(int i = 10; i < MAX; i++){
		a[i] = 0;
		int k = i;
		while(k) {
			a[i] += a[k%10];
			k/=10;
		}
		//printf("a[%d]= %d\n", i, a[i]);
	}
		
	for(int i = 0; i < MAX/2; i++) {
		for(int j=0; j < MAX/2; j++) {
				if(a[i] + a[j] + a[i+j] + 4 == n) {
					cnt++;
					//printf("%d: %d + %d = %d\n", cnt, i , j , i+j);
				}
					
			}
	}
	
	printf("%d", cnt);
}
