#include<bits/stdc++.h>

using namespace std;

int m, t, s, ans;

int main() {

    scanf("%d %d %d", &m, &t, &s);
   
  	ans = m - s / t;
  	if(s % t)
  		ans--;
	if(ans < 0)
		ans = 0;
   
   	printf("%d", ans);
   	
    return 0;
}
