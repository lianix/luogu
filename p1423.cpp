#include <cstdio>

using namespace std;

int main()
{
	double sum = 2.0, step = 2.0, d;
	int n = 1;
		
	scanf("%lf", &d);

	while(sum < d){
		n++;
		step = step * 0.98;
		sum += 	step;
	}
	
	printf("%d\n", n);
	
	return 0;
}

