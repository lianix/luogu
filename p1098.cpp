#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3;
char a[108], b[100008];
int bi;
char t;


int main()
{
	scanf("%d %d %d", &p1, &p2, &p3);
	scanf("%s", a);

	int i = 0;
	char start, end;
	while(a[i] != '\0') {
		if(a[i] != '-') {
			b[bi++] = a[i++];
			continue; 
		}
		// i ÊÇ'-' 
		start = a[i-1];
		end = a[i+1];
		if(end == start + 1) {
			b[bi++] = a[i+1];
			i += 2;
			continue; 
		} else if(end <= start) {
			b[bi++] = a[i++];
			continue;
		} else if ((start >='0' && start <= '9') &&
		 		(end >='0' && end <= '9')) {
		 	i++;
		 	if(p3 == 1) {
				//ÕıĞò 
				for(t = start + 1; t < end; t++){
					for(int k = 0; k < p2; k++) {
						if(p1 == 3)
							b[bi++] = '*';
						else
							b[bi++] = t;
					}
				}	
			} else {
				//ÄæĞò 
				for(t = end - 1; t > start; t--){
					for(int k = 0; k < p2; k++) {
						if(p1 == 3)
							b[bi++] = '*';
						else
							b[bi++] = t;
					}
				}	
			}			
 		} else if((start >='a' && start <= 'z') &&
		 		(end >='a' && end <= 'z')) { 
		 	i++;
			//²åÈë×Ö·û 
			if(p3 == 1) {
				//ÕıĞò 
				for(t = start + 1; t < end; t++){
					for(int k = 0; k < p2; k++) {
						if(p1 == 3)
							b[bi++] = '*';
						else if (p1 == 2)
							b[bi++] = t - 'a' + 'A';
						else
							b[bi++] = t;
					}
				}	
			} else {
				//ÄæĞò 
				for(t = end - 1; t > start; t--){
					for(int k = 0; k < p2; k++) {
						if(p1 == 3)
							b[bi++] = '*';
						else if (p1 == 2)
							b[bi++] = t - 'a' + 'A';
						else
							b[bi++] = t;
					}
				}			
			}
		} else {
			b[bi++] = a[i++];
		}
		
	}
	b[bi]='\0';
	
	printf("%s", b);
	
	return 0;
}
