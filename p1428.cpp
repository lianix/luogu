#include <cstdio>
using namespace std;

int n;
int fish[105];
int love[105];

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &fish[i]);
	}
	
	for(int i =0; i < n; i++)
	{
		love[i] = 0;
		for(int j=0; j < i; j++)
		{
			if(fish[j] < fish[i])
				love[i]++;
		}
		
	}
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", love[i]);
	}
	return 0;
} 
