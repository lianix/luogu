#include <cstdio>
using namespace std;

int a[101], b[101];
int n, sum,ans; 

int f(float *f);
int f(int d)
{
	
}
int main()
{
	scanf("%d", &n);
	for(int i =0; i < n; i++)
		scanf("%d", &a[i]);
		
	for (int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++)
		{
			sum = a[i] + a[j];
			//printf("sum a[%d]+ a[%d]= %d\n", i, j, sum);
			for (int k = 0; k < n; k++) {
				if (a[k] == sum) {
					if (b[k] == 0) {
						b[k] = 1;
						ans++;
					}
				}
			}
		}
	}	
	printf("%d", ans);
	
	return 0;
}

