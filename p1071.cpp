#include <bits/stdc++.h> 

char a[108], b[108], c[108], d[108];
int alen, clen;
char k[28]; //��¼�������� 
bool flag = true;

void map(char x, char y)
{
	int i;
	int idx = x - 'A';
	for(i = 0; i < 26; i++){
		if(k[i] == y)
			break;
	}
	
	if(i == 26) { //û�в���
		//���в������ 
		if(k[idx] == 0){
			k[idx] = y;  
		} else {
			//��ǰi�Ѿ�������������ַ�,����ʧ��
			flag = false; 
		} 
	} else { //�ҵ��� 
		if(i != idx) //�Ѿ�������������ַ� 
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
			printf("%s", "Failed"); //δ����ɹ� 
			return 0;
		}
	}
	
	d[clen] = '\0';
	
	printf("%s", d);
	return 0;
}
