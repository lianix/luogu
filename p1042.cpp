#include <bits/stdc++.h>
using namespace std;

int a11[10000], b11[10000];
int a21[10000], b21[10000];
int cnt11, cnt21;
char c;

int main()
{
	while(c = getchar()) {
		if(c == 'E')
			break;
			
		if(c=='W') { 
			a11[cnt11]++;
			a21[cnt21]++;
		} else if(c == 'L') {
			b11[cnt11]++;
			b21[cnt21]++;
		} else
			continue;
		
		if(a11[cnt11] >= 11 || b11[cnt11] >= 11) {
			if(abs(a11[cnt11] - b11[cnt11]) >= 2)
				cnt11++;
		}
		
		if(a21[cnt21] >= 21 || b21[cnt21] >= 21) {
			if(abs(a21[cnt21] - b21[cnt21]) >= 2)
				cnt21++;
		}
	}
	
		int i;
		for(i = 0; i <= cnt11; i++) {
			printf("%d:%d\n", a11[i], b11[i]);
		}
	//	if(a11[cnt11] != 0 || b11[cnt11] != 0 || cnt11 == 0)
	//		printf("%d:%d\n", a11[cnt11], b11[cnt11]);
		
		printf("\n"); 
		
		for(i = 0; i <= cnt21; i++) {
			printf("%d:%d\n", a21[i], b21[i]);
		}
		//if(a21[cnt21] != 0 || b21[cnt21] != 0 || cnt21 == 0)
		//	printf("%d:%d\n", a21[cnt21], b21[cnt21]);	
			
		return 0;
}


