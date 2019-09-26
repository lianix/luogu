#include <bits/stdc++.h>
using namespace std;

int ep, emax, base, drop;
int subsidy, tax, earning;
int cnt[1000008]; //下标是价格
int max_price;

int main()
{
	int i, price, pre_price, tmp;
	
	scanf("%d", &ep);
	scanf("%d", &base);
	scanf("%d", &cnt[base]);
	pre_price = base;
	while(1) {
		scanf("%d %d", &price, &tmp);
		if(price == -1)
			break;
		cnt[price] = tmp;
		drop =  (cnt[pre_price] - cnt[price]) / (price - pre_price);
		for(i = pre_price + 1; i < price; i++){
			cnt[i] = cnt[i - 1] - drop; 
		}
		pre_price = price;
	}
	scanf("%d", &drop);
	
	for(i = pre_price + 1; ;i++) {
		cnt[i] = cnt[i-1] - drop;
		if(cnt[i] <= 0)
			break;
	}
	max_price = i-1;
	
	for( i = base; i <= max_price; i++) {
	//	printf("==: %d %d\n", i, cnt[i]);
	}
	//printf("ep=%d\n", ep);
	//x = abs(pc[idx-1].cnt / drop - 1 + base - pc[idx-1].price);
	

	
	bool find1 = false;
	subsidy = 0;
	while(!find1) {
	//	printf("putie-x=%d\n", x);
		emax = (ep-base + subsidy) * cnt[ep];
		if(subsidy * cnt[base] > emax) //成本价销售, 反而收益更大  补贴过多啊 
			break;
			
		for(i=base + 1; i<= max_price; i++)
		{
			earning = (i - base + subsidy) * cnt[i];
	//		printf("%d: earning:%d emax=%d\n", i, earning, emax);
			if(earning > emax)
				break;		
		}
		if(i > max_price)
			find1 = true;
		else
			subsidy++;
	}
	
	//////////////////////////
	bool find2 = false;
	tax = -1;
	while(!find2) {
	//	printf("putie-x=%d\n", x);
		emax = (ep-base+tax) * cnt[ep];
		if(emax <= 0) //没利润了啊 
			break;
			
		for(i=base + 1; i<= max_price; i++)
		{
			earning = (i - base + tax) * cnt[i];
	//		printf("%d: earning:%d emax=%d\n", i, earning, emax);
			if(earning > emax)
				break;		
		}
		
		if(i > max_price)
			find2 = true;
		else
			tax--;
	}
	
	if(find1 && find2) {
		if(subsidy > -tax) {
			printf("%d", tax);
		} else {
			printf("%d", subsidy);
		}
	} else if(find1) {
		printf("%d", subsidy);
	} else if(find2) {
		printf("%d", tax);

	} else
	 printf("NO SOLUTION");
	 
	return 0;
	 		
}
