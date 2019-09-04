#include <cstdio>
using namespace std;


int main()
{

int budget = 0, ans = 0, shengyu = 0; 
int flag = 0;

	for(int i = 1; i <=12; i++) {
		scanf("%d", &budget);
		shengyu = 300 + shengyu - budget;
		if (shengyu < 0) {
			if (flag == 0)
				flag = -i;
		}
		
		ans += (shengyu / 100 ) * 100;
		//printf("%d %d\n", shengyu, ans);
		shengyu = shengyu % 100;	
	}
	
	if (flag < 0) {	
		printf("%d\n", flag);
	}
	else {
		ans = ans + ans * 0.2  + shengyu;
		printf("%d\n", ans);
	}
	
	return 0;
}
