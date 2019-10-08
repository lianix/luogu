#include <bits/stdc++.h>
using namespace std;

int n, m;
struct Milk {
	int p;
	int a;
};

Milk milk[5008];

bool compare(Milk m1, Milk m2)
{
	return m1.p < m2.p;
}


int main()
{
	int i;
	int cnt = 0, money = 0;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d",
			 &milk[i].p, &milk[i].a);
	}

	sort(milk, milk+m, compare);
	
	for(i = 0; i < m; i++) {
		if(cnt + milk[i].a >= n){
			money += (n-cnt) * milk[i].p;
			break;
		}	else {
			cnt += milk[i].a;
			money += milk[i].a * milk[i].p;
		}
	}
	
	printf("%d", money);
	
	return 0;
}
