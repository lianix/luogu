#include <bits/stdc++.h>
using namespace std;

char num[][20] ={
"zero",
"one", "two", "three", "four",
"five", "six", "seven", "eight",
"nine",  "ten", "eleven", "twelve",
"thirteen", "fourteen", "fifteen", "sixteen",
"seventeen", "eighteen", "nineteen", "twenty"};

char b[][20] = {"0", "a", "both" };
char c[][20] = {"0", "first", "second", "third"};
char d[] = "another";

int  cnt[100]; 
char str[1000];

int main()
{
	int i = 0;
	while(1) {
		str[i] = getchar();
		if(str[i] >= 'A' && str[i] <='Z')
			str[i] = str[i] - 'A' + 'a';
		if(str[i] == '.') {
			str[i] = '\0';
			break;
		}
		i++;
	}
	
	char *p;
	int idx = 0;
	p = str;
	char tmp[100];
	int rt;
	while(1) {
		rt = sscanf(p, "%s", tmp);
		//printf("%d %s\n", rt, tmp);
		if (rt != 1)
			break;
		p += strlen(tmp) + 1;
		//±È½Ï ¼ÆËã 
		for(i = 1; i <= 20; i++) {
			if(strcmp(tmp, num[i]) != 0)
				continue;  
			cnt[idx] = (i*i)%100;
			idx++;
		}	
		
		for(i = 1; i <= 2; i++) {
			if(strcmp(tmp, b[i]) != 0)
				continue;  
			cnt[idx] = (i*i)%100;
			idx++;
		}	
		
		for(i = 1; i <= 3; i++) {
			if(strcmp(tmp, c[i]) != 0)
				continue;  
			cnt[idx] = (i*i)%100;
			idx++;
		}	
		
		if(strcmp(tmp, d) == 0) {
			cnt[idx] = (2*2)%100;
			idx++;
		}	
	}
	
	sort(cnt, cnt + idx);
	int flag = 0;
	for(i = 0; i<idx; i++) {
		if(flag == 1) {
			printf("%02d", cnt[i]);
		} else {
			if(cnt[i] == 0)
				continue;
			printf("%d", cnt[i]);
			flag = 1;
		}
	}
	
	if (idx == 0)
		printf("0");
		
	return 0;
} 
