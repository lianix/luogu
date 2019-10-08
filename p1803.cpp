#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;

struct line{
    int start;
    int end;
};

line l[1000008];
bool compare(line l1, line l2){
	return l1.end < l2.end;
}

int main()
{
	int i, tend;
	
    scanf("%d",&n);
    for(i=0; i<n; i++) {
    	scanf("%d %d", &l[i].start, &l[i].end);
	}
	sort(l, l+n, compare);
	
	tend = 0;
	for(i=0; i<n; i++) {
		if(l[i].start>=tend) {
			cnt++;
			tend=l[i].end;
		}
    }
	
	printf("%d", cnt);
	
	return 0;
}
