#include <cstdio>
using namespace std;

int a[20002];
int b[10000];
int k, n;

void prime()
{
	for(int i = 2; i <20000; i++) {
		if(a[i] != 0) {
			continue;
		}
		
		b[k++] = i; // is prime
		
		for(int j=2; j < 20000/i; j++) {
			a[i * j] = 1;
		}		
	}
}

int main()
{
	scanf("%d", &n);
	prime();
	for(int x = 0; x < k; x++) {
		for(int y = 0; y < k; y++) {
			for(int z = 0; z < k; z++) {
				if(b[x] + b[y]+ b[z] == n) {
					printf("%d %d %d", b[x], b[y], b[z]);
					return 0;
				}
				
			}
		}
	}	
}
