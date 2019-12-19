#include <bits/stdc++.h>
using namespace std;

char word[108];
int a[26];
int maxn = 1, minn = 1, n;

bool isprime(int n)
{
	if(n < 2)
		return false;

	for(int i=2; i*i <=n; i++) {
		if(n % i == 0)
			return false;
	}
	
	return true;
}

int main()
{
	int i;
	
	scanf("%s", word);
	int len = strlen(word);
	
	for(i = 0; i < len; i++) {
		a[word[i] - 'a']++;
	}
	
	sort(a, a+26);
	
	i = 0;
	while(a[i] == 0) {
		i++;
	}
	
	minn = a[i];
	maxn = a[25];
	
	n = maxn - minn;
	
	if(isprime(n)) {
		printf("Lucky Word\n%d", n);
	} else {
		printf("No Answer\n%d", 0);
	}
	
	return 0;
}

