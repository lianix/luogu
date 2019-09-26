#include <cstdio>
using namespace std;

int sum;
int c, x, ax, a;
int tmp = 0;
int flag = 0; //1+  //2- 
int equal;
int main()
{
	int flag = 1;
	
	while(1){
		c= getchar();
		if(c=='\n' || c==EOF){
			break;
		}
		
		if(c=='=') {
			equal = 1;
			if(tmp!=0) {
				a+=tmp * flag;
				tmp = 0; 
			}
			flag = -1;
		} else if(c=='+') {
			if(tmp!=0) {
				a+=tmp * flag;
				tmp = 0; 
			}
			flag = 1;
			if(equal == 1) {
				flag = -1;
			}
		} else if(c=='-') {
			if(tmp!=0) {
				a+=tmp * flag;
				tmp = 0; 
			}
			flag = -1;
			if(equal == 1) {
				flag = 1;
			}
		} else if(c>='a' && c <='z'){
			x = c;
			if(tmp == 0)
				tmp = 1;
			ax += tmp * flag;
			tmp = 0;
		} else if(c>='0' && c <='9'){
			tmp = 10 * tmp + (c-'0');
		}	
		
		//printf("a=%d ax=%d tmp=%d flag=%d c=%c\n", a, ax, tmp, flag, c);
	}
	
	if(tmp!=0) {
		a+=tmp * flag;
		tmp = 0; 
	}
	
	//printf("a=%d ax=%d tmp=%d c=%c\n", a, ax, tmp, c);
 	if(a==0) {
        printf("%c=%.3f",x, 0);
        return 0;
    }
    
	printf("%c=%.3f",x,a*(-1.0)/ax);
	return 0;	
}
