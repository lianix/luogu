#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

//从first到x中选cnt个数,和等于x; 
void find(int first, int x, int cnt)
{
//	printf("%d %d %d ans=%d\n", first, x, cnt, ans);
	if(cnt==1) { // 已经保证x >= first;选x, 和等于x. 
		ans++;
		return;
	}
	
	int newx;
	int last = first + (x - first)/cnt; //选前面得cnt分之一 
	for(int i = first; i <= last; i++)
	{
		//选择了i, 那么这个i 也是新的first
		newx = x - i;
	//	printf("%d: i = %d, %d  cnt %d \n", x, i, newx, cnt);  
	
		if(newx < i)//只能升序排列 
			break;
		find(i, newx, cnt - 1);		
	} 
}

int main()
{
	scanf("%d %d", &n, &k);	
	
	find(1, n, k);
	
	printf("%d", ans);
	
	return 0;
}
