#include <cstdio>
#include <cstring>
using namespace std;

char buf[55];
char c[27]="abcdefghijklmnopqrstuvwxyz";
int n, idx;

int main()
{
	scanf("%d", &n);
	scanf("%s", buf);
	
	for(int i=0; i < strlen(buf); i++){
		idx = buf[i] - 'a';
		idx = (idx +n)%26;
		printf("%c", c[idx]);
	}
	
	return 0;
}
