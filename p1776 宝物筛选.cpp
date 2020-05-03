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
		
		//�������Ϊ0����� 
		if(wi == 0) {
			ans += mi * vi;
			continue;
		}
		
		//����ѡ����Ʒ���� 
		int total = min(mi, w / wi);
		for(int j=0; j<wi; j++){ //ö��ÿһ������ 
			int k = (w-j)/wi; // �������� ��Ʒ���� 
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
