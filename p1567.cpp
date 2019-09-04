#include <cstdio>
using namespace std;

int n;
int days = 0, max = 1;
int tmp1=0, tmp2;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++){
		scanf("%d", &tmp2);
		if(tmp2 >= tmp1) {
			days++;
			tmp1 = tmp2;
		} else {
			tmp1 = tmp2;
			if(days > max)
				max = days;
			days = 1;
		}
	}
	
	if (days>max)
		max = days;
		
	printf("%d", max);
	
	return 0;
}
