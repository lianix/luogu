#include <cstdio>
using namespace std;

float s, x;
float sum, speed = 7.0;

int main()
{
	scanf("%f %f", &s, &x);
	while(sum < (s-x))
	{
		sum+= speed;
		speed = speed * 0.98;	
	}
	
	if(sum + speed > s+x)
		printf("n");
	else
		printf("y");
		
	return 0;
}
