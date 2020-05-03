#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <algorithm>
 
using namespace std;

const int MAXN = 40006;
int n, w, tmp, ans;
int f[MAXN], que[MAXN], num[MAXN];

int main() {
	scanf("%d %d", &n, &w);
	
	for(int i=1; i<=n; i++){
		int vi, wi, mi;
		scanf("%d %d %d", &vi, &wi, &mi);
		
		//避免除数为0的情况 
		if(wi == 0) {
			ans += mi * vi;
			continue;
		}
		
		//最多可选的物品数量 
		int total = min(mi, w / wi);
		for(int j=0; j<wi; j++){ //枚举每一个余数 
			int k = (w-j)/wi; // 该余数下 物品数量 
			int head=1,tail=0;
			for(int ki=0; ki<=k; ki++){
				int qv=f[j+k*wi]-k*vi;
				while(head<=tail && 
					  qv >= que[tail])
					  tail--;
				tail++;
				que[tail] = qv; 
				num[tail]= ki;
				
				while(head<=tail&&
					num[head]+total<ki)
						head++;
				f[j+k*wi] = max(f[j+k*wi], que[head]+k*vi);
				tmp = max(tmp, f[j+k*wi]);
			} 
		} 
	}
	
	printf("%d", tmp+ans);
	return 0;
} 
