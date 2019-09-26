#include <cstdio>
using namespace std;

int n,i;
int a[10000000][10];

int main()
{
	scanf("%d", &n);
	if (n > 30 || n < 10) {
		printf("0");
		return 0;
	}
	
	for(int a1 =1; a1 <=3; a1++) {
		for(int a2 =1; a2 <=3; a2++) {
			for(int a3 =1; a3 <=3; a3++) {
				for(int a4 =1; a4 <=3; a4++) {
					for(int a5 =1; a5 <=3; a5++) {
						for(int a6 =1; a6 <=3; a6++) {
							for(int a7 =1; a7 <=3; a7++) {
								for(int a8 =1; a8 <=3; a8++) {
									for(int a9 =1; a9 <=3; a9++) {
										for(int a10 =1; a10 <=3; a10++) {
											if (a1+a2+a3+a4+a5+a6+a7+a8+a9+a10 == n)
											{
												a[i][0]=a1;
												a[i][1]=a2;
												a[i][2]=a3;
												a[i][3]=a4;
												a[i][4]=a5;
												a[i][5]=a6;
												a[i][6]=a7;
												a[i][7]=a8;
												a[i][8]=a9;
												a[i][9]=a10;
												i++;
											}
										}
									}
								}
							}
						}	
					}
				}
			}
		}
	}
	
	printf("%d\n", i);
	
	for(int k=0; k <i; k++) {
		for(int j=0; j < 10; j++) {
			printf("%d ", a[k][j]);
		}
		printf("\n");
	}
	
			
	return 0;
}
