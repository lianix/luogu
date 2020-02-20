#include <bits/stdc++.h>
using namespace std;

char strs[22][201];
int lens[22];
int cnt[22];

int n, maxlen;

char *strrchr(char *start, char *limit, char c)
{
	while(start >= limit) {
		if (*start == c)
			return start;
		else 
			start--;
	}
	
	return NULL;
}

int joint(int idx1, int idx2)
{
	char *p1, *p2, *start, *end, *limit;
	int len;

	p1 = strs[idx1];
	p2 = strs[idx2];
	end = start = p1 + lens[idx1] - 1;
	limit = start - lens[idx2] + 2;

	if(limit <= p1)
		limit = p1 + 1;

	while((start = strrchr(start, limit, p2[0])) != NULL) {
		len = end - start + 1;
		if(strncmp(start, p2, len) == 0)
			return len;
		start--;
	}
	
	return 0;	
}

void dfs(int idx, int len)
{
	int chonghe;
	
	cnt[idx]++;
	len += lens[idx];
	
	if(len > maxlen)
		maxlen = len;
		
	for(int i = 0; i < n; i++) {
		if(cnt[i] == 2)
			continue;
	
		chonghe = joint(idx, i);
		if(chonghe > 0) {
			dfs(i, len - chonghe);	
		}
	}
	
	cnt[idx]--;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		scanf("%s", strs[i]);
		lens[i] = strlen(strs[i]);
	}
	int i;	
	for(i = 0; i < n; i++)
		if(strs[i][0] == strs[n][0]) {
			dfs(i, 0);
		}
	
	printf("%d", maxlen);
	return 0;
}
