#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int a[100];

int main() {
	int i, j; 
   
   	a[0] = 1;
   	a[1] = 1;
   	a[2] = 2;
   	a[3] = 4;
   	for(int i = 3; i <= 10; i++) {
   		a[i] = a[i - 1] + a[i - 2] + a[i -3];
   		if(i == 6)
   			a[6] = 0;
   		printf("%d Ì¨½× ×ß·¨:%d\n", i, a[i]);
	   }
	   
    return 0;
}
