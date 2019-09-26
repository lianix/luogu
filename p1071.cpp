#include <bits/stdc++.h> 

char a[108], b[108], c[108], d[108];
int alen, clen;
char k[28]; //记录解密数据 
bool flag = true;

void map(char x, char y)
{
	int i;
	int idx = x - 'A';
	for(i = 0; i < 26; i++){
		if(k[i] == y)
			break;
	}
	
	if(i == 26) { //没有插入
		//进行插入操作 
		if(k[idx] == 0){
			k[idx] = y;  
		} else {
			//当前i已经被翻译成其他字符,插入失败
			flag = false; 
		} 
	} else { //找到了 
		if(i != idx) //已经被翻译成其他字符 
			flag = false;
	}  
}

int main()
{
	scanf("%s %s %s", a, b,c);
	//printf("debug:%s\n%s\n%s\n", a, b,c);
	
	alen = strlen(a);
	for(int i = 0; i < alen; i++) {
		map(a[i], b[i]);
		if(flag == false) {
			printf("%s", "Failed");
			return 0;
		}
	}	
	
	for(int i = 0; i < 26; i++) {
		if(k[i] == 0) {
			printf("%s", "Failed");
			return 0;
		}
	} 
	
	clen = strlen(c);
	for(int i=0; i < clen; i++){
		d[i] = k[c[i]- 'A'];
		if(d[i] == 0) {
			printf("%s", "Failed"); //未翻译成功 
			return 0;
		}
	}
	
	d[clen] = '\0';
	
	printf("%s", d);
	return 0;
}
