#include<bits/stdc++.h>
using namespace std;
int main()
{
 char code[4][106];
 int a,b=0,c,d,i,j,num[26],l[400];
 for(i=0;i<=3;i++)
  for(j=0;j<=105;j++)
   {
  scanf("%c",&code[i][j]);
 if(code[i][j]=='\n') break;
   }
 
 for(i=0;i<26;i++)
  num[i]=0;

 for(i=0;i<=3;i++)
   for(j=0;j<=105;j++)
   {
  if(code[i][j]=='\n' || code[i][j]== -1 ) break;
  if (code[i][j] >= 'A' && code[i][j]<='Z') {
  	a=code[i][j]-'A';
  	num[a]++;
	}
   }
 for(i=0;i<26;i++)
  {
   if(num[i]>b)
      b=num[i];
  }

  for(i=0;i<b;i++)
    for(j=0;j<26;j++)
      if (num[j]>=b-i) l[i]=j;
  
  for(i=0;i<b;i++)
    for(j=0;j<=50;j++)
   {
    
    if((i>=b-num[j/2])&&j%2==0) {printf("*");}
    else if(j<=2*l[i]) printf(" ");
    if(j==2*l[i]) {printf("\n");}
   }
   for(j=0;j<51;j++)
     if(j%2==0) printf("%c",j/2+'A');
     else  printf(" ");
  return 0;
}
