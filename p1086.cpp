#include <bits/stdc++.h>
using namespace std;

struct peanut {
	int num;
	int m;
	int n;
};

int n, m, k, ans;
peanut p[400];
int cnt;
int t;

bool compare(peanut p1, peanut p2)
{
	return p1.num > p2.num;
}

int main()
{
	int tmp;
	
	scanf("%d %d %d", &m, &n, &k);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++){
			scanf("%d", &tmp);
			if(tmp > 0) {
				p[cnt].num = tmp;
				p[cnt].m = i;
				p[cnt].n = j;
				cnt++;
			}
		}
		
	sort(p, p+cnt, compare);
	
	t = 0;
	ans = 0;
	for(int i = 0; i < cnt; i++){
		if(i == 0)
			t += p[i].m;
		else
			t += abs(p[i].m - p[i-1].m) + abs(p[i].n - p[i-1].n);
		t += 1;
		if(t + p[i].m > k)
			break;
		ans += p[i].num; 
	}
	
	printf("%d", ans);
	return 0;
}
