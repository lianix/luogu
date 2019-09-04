#include <cstdio>

using namespace std;

int a, b;
int day = 0;
int time = 0;

int main()
{
	for(int i = 1; i <=7; i++) {
		scanf("%d %d", &a, &b);
		if (time >= (a + b)) 
			continue;
		time = a + b;
		if (time > 8)
			day = i;
	}
	
	printf("%d\n", day);
	
	return 0;
}

