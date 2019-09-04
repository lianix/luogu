#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int num[10];
int a, b,c, i;
int first, second, third;
int main()
{
	for(a = 1; a <=3; a++) {
		for(b = 1; b <=9; b++){
			if (a == b)
				continue;
			for(c = 1; c <=9; c++) {
				if (c == a || c==b)
					continue;
				first = a*100 + b *10 + c;
				second = first *2;
				third = first*3;
				if (third > 987)
					continue;
				memset(num, 0, sizeof(num));
				num[a]++;
				num[b]++;
				num[c]++;
				num[second%10]++;
				num[second/100]++;
				num[(second/10)%10]++;
				num[third%10]++;
				num[third/100]++;
				num[(third/10)%10]++;
				for (i = 1; i <=9; i++) {
						if(num[i] != 1)
							break;
				}
				
				if (i == 10)
					printf("%d %d %d\n", first, second, third);
				
			}
		}
	}
		
	return 0;
}
