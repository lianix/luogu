#include <cstdio>
#include <cstring>

using namespace std;

char star[7];
char group[7];
long long star_name=1, group_name=1;

int main()
{
	scanf("%s", star);
	scanf("%s", group);
	
	for(int i=0; i < strlen(star); i++)
		star_name *= star[i] - 'A' + 1;
	for(int i=0; i < strlen(group); i++)
		group_name *= group[i] - 'A' + 1;
		
	if(star_name % 47 == group_name % 47)
		printf("GO");
	else
		printf("STAY");
		
	return 0;
}
