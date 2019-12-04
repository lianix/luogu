#include <bits/stdc++.h>
using namespace std;

int n;
struct task {
  int len;
  vector<int> kl;
};
task k[10001]; 
int maxlen, len;

int main()
{
	int i, p; 
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d %d", &p, &k[i].len);
		while(true) {
			scanf("%d",&p);
			if(p == 0)
				break;
			k[i].kl.push_back(p);
		}
	}

	for(i = 1; i <= n; i++) {
		len = 0;
		for(int j = 0; j < k[i].kl.size(); j++) {
			len = max(len, k[k[i].kl[j]].len);
		}
		k[i].len += len;
		maxlen = max(k[i].len, maxlen);
	}

	printf("%d", maxlen);
	return 0; 
}
