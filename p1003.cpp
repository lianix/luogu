#include <cstdio>
using namespace std;

int n;

struct ax{
	int a;
	int b;
	int g;
	int k;
};

struct ax d[10005];

int x, y, i;

int main()
{
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d %d %d %d", 
			&d[i].a, &d[i].b,
			&d[i].g, &d[i].k);
	}

	scanf("%d %d", &x, &y);
	
	for(i = n; i > 0; i--){
		if(x>= d[i].a && x <= (d[i].a + d[i].g) &&
			y>=d[i].b && y <= (d[i].b + d[i].k))
			break;
	}
	
	if(i > 0)
		printf("%d", i);
	else
		printf("-1");
		
	return 0;
} 

