#include <bits/stdc++.h>
using namespace std;

#define DEBUG  
#ifdef DEBUG  
#define debug(format,...) printf(format, ##__VA_ARGS__)  
#else  
#define debug(format,...)  
#endif 

int n, k;
int power;
char pstr[10];
char fstr[20];
int cp;
int ans[108];

struct func {
	char x[2];
	char start[10];
	char end[10];
}; 

func f[108];
int  fp[108];
int fi; 

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d O(%[^)]%*[^\n]%*c", &k, pstr);
		debug("@@: %s\n", pstr);
		if(pstr[0] >= '0' && pstr[0] <='9') {
			power = 0;
		} else if (pstr[0] == 'n') {
			int j = 2;
			power = 0;
			while(pstr[j] != '\0') {
			//	printf("@@%c\n", pstr[j]);
				power = power * 10 +  (pstr[j] - '0');
				j++;
			}		
		}
		debug("k:%d power: %d\n", k, power);
		cp = 0;
		fi = 0;
		memset(fp, 0, sizeof(fp)); 
		while(k > 0) {
			k--;
			scanf("%[^\n]%*c", fstr);
			//printf("k: %s\n", fstr);
			//gets(fstr);
			if (cp == -1)
				continue;
			if(fstr[0] == 'F') {
				fi++;
				sscanf(fstr, "F %s %s %s", f[fi].x, f[fi].start, f[fi].end);
				if(fi > 1) {
					for(int j = 1; j < fi; j++)
					if(f[j].x[0] == f[fi].x[0]) { //是否使用未销毁变量 
						cp = -1;
						continue;
					}
				}
				fp[fi] = 0; 
			} else if(fstr[0] == 'E') {
				if (fi == 0) {
					cp = -1;
					continue;
				} else {
					if (f[fi].start[0] == 'n') {
						if(f[fi].end[0] != 'n')
							fp[fi] = 0; //不被执行,从0开始吧
						else
							;// 常数 power 不变 
					} else if (f[fi].end[0] == 'n') {
						fp[fi]++;
					} else {
						if (atoi(f[fi].end) <= atoi(f[fi].start)) {
							// end < start
							fp[fi] = 0; //不被执行,从0开始吧 
						} else {
							// 常数 power 不变 
							;
						}
					}		
				}
				debug("fp: 0->%d %d->%d\n", fp[0], fi, fp[fi]);
				if(fp[fi] > fp[fi -1])
					fp[fi-1] = fp[fi];
				fp[fi] = 0; //清空 
				fi--;
			}
		}
		
		debug("fp: 0->%d cp:%d\n", fp[0], cp);
		
		if(fi != 0)
			cp = -1;
			
		if(cp == -1) {
			ans[i] = -1;
		} else if (power == fp[0])
			ans[i] = 1;
		else
			ans[i] = 0;
	}	
	
	for(int i = 0; i < n; i++) {
		if(ans[i] == -1) {
			printf("ERR\n");
		} else if (ans[i] == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
		
}
