#include <cstdio>
 
using namespace std;

char a[14];
int ans = 0;
 
int main()
{
	//0-670-82162-4
	scanf("%s", a);
	int b = 1;
	
	for(int i=0; i < 11; i++)
	{
		if (i ==1)
			continue;
		if (i == 5)
			continue;
		ans+= (a[i] - '0') * b;
		b++;
	}	
	
	ans %= 11;
	if (ans == 10)
		ans = 'X';
	else
		ans += '0';
	
	if (a[12] == ans)
		printf("Right");
	else {
		a[12] = ans;
		printf("%s", a);
	}
		
	return 0;
}
