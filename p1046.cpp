#include <cstdio>

using namespace std;

int height[10];
int hand;
int i, ans = 0;

int main()
{
	for(int i = 0; i < 10; i++){
		scanf("%d", &height[i]);
	}
	
	scanf("%d", &hand);
	
	for(int i = 0; i < 10; i++){
		if(height[i] <= (hand + 30))
			ans++;
	}
	
	printf("%d", ans);

	return 0;
}

