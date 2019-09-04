#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct apple{
	int xi;
	int yi;
};

int n, s;
int a, b;
int cnt = 0;

struct apple apple[5005];

bool compare(struct apple a1, struct apple a2)
{
	return(a1.yi < a2.yi);
}

int main()
{
	int x, y, k=0;
	scanf("%d %d", &n, &s);
	scanf("%d %d", &a, &b);
	for(int i=0; i <n; i++){
		scanf("%d %d", &x, &y);
		if (x > a+b)
			continue;
		apple[k].xi = x;
		apple[k].yi = y;
		k++;
	}
	
	sort(apple, apple+k, compare);
	
	for(int i = 0; i < k; i++)
	{
		if(s >= apple[i].yi) {
			s -= apple[i].yi;
			cnt++;
		} else
			break;
	}
	
	printf("%d", cnt);
	
	
}
