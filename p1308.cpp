#include <cstdio>
#include <cstring>

char word[11];
char str[11];

int len, start=0, idx=0, count=0, pos=0, flag = 1;
char x;

int main(){
	scanf("%s", word);
	len = strlen(word);
	for(int i =0; i < len; i++){
		if(word[i] >= 'a' && word[i]<='z')
			word[i] = word[i] - 'a' + 'A';
	}
	
	getchar();
	
	while((x=getchar())!= EOF){
		pos++;	
		if (x == ' '){
			if(idx == len) {
				count++;
				if(count == 1)
					start = pos - len -1;
			}
			idx = 0;
			flag = 1;
			continue;
		}
		
		if(flag != 1)
			continue;
			
		if(x >= 'a' && x<='z')
			x = x - 'a' + 'A';
			
		if(x==word[idx]){
			idx++;
		} else {
			idx = 0;
			flag = 0;
		}	
	}
	
	if(count)
		printf("%d %d", count, start);
	else
		printf("-1");
		
	return 0;
}
