#include <cstdio>
using namespace std;

int k, ans=0, num, num_days;

int main()
{
	//freopen("coin.in", "r", stdin);
	//freopen("coin.out", "w", stdin);	
	
	scanf("%d", &k);
	num = 1;
	num_days = 0;
	
	for(int i = 1; i<=k; i++){
		num_days++;
		
		if(num_days <= num) {	
			ans += num;
			//printf("%d   %d\n", i, num);
		}
		
		else {
			num_days=1;
			num++;
			ans += num;
			//printf("%d   %d\n", i, num);
		}		
	}
	
	printf("%d", ans);
	
	return 0;
} 
