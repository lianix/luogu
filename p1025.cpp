#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

//��first��x��ѡcnt����,�͵���x; 
void find(int first, int x, int cnt)
{
//	printf("%d %d %d ans=%d\n", first, x, cnt, ans);
	if(cnt==1) { // �Ѿ���֤x >= first;ѡx, �͵���x. 
		ans++;
		return;
	}
	
	int newx;
	int last = first + (x - first)/cnt; //ѡǰ���cnt��֮һ 
	for(int i = first; i <= last; i++)
	{
		//ѡ����i, ��ô���i Ҳ���µ�first
		newx = x - i;
	//	printf("%d: i = %d, %d  cnt %d \n", x, i, newx, cnt);  
	
		if(newx < i)//ֻ���������� 
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
