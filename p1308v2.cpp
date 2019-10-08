#include <bits/stdc++.h>

char s[1000008], w[18];
int ls, lw;
char *p;
int pos, ans;

int main () {
    gets(w+1);
    gets(s+1);//输入
    w[0] = ' ';
    s[0] = ' ';
    
	ls = strlen(s);
    lw = strlen(w);
    
    w[lw++] = ' ';
    w[lw] = '\0'; 
    
    s[ls++] = ' ';
    s[ls] = '\0';
	 
    p = w;
    while(*p != '\0') {
    	if(*p >= 'a' && *p <='z')
    		*p = *p - 'a' + 'A';
    	p++; 
	}
	p = s;
	while(*p != '\0') {
    	if(*p >= 'a' && *p <='z')
    		*p = *p - 'a' + 'A';
    	p++; 
	}
	
	p = s;
	
	while(p = strstr(p, w)) {
		ans++;
		if(ans == 1)
			pos = p - s;
		p += lw - 1;
	}
     

    if(ans)//找到了
        printf("%d %d" , ans, pos);//输出
    else 
        printf("-1");//输出-1

    return 0;
}
