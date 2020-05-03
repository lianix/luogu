#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,i,n,j;
bool l;
int main()
{
    //freopen("order.in","r",stdin);
 //freopen("order.out","w",stdout);
 scanf("%d",&n);
 a=b=c=n/14;
 d=n%14;
 if(d==0)
 {
  printf("%d %d %d",a,b,c);
  return 0;
 }
 for(l=true;l&&d<=n;a--,b--,c--,d+=14)
 {
  for(i=d/3;i>=0&&l;i--) 
  {
   for(j=(d-3*i)/4;j>=0&&l;j--) 
   {
    if((d-3*i-4*j)%7==0)
    {
     l=false;
     a+=(d-3*i-4*j)/7;
     b+=j;
     c+=i;
     break;
    }
   }
  }
 }
 if(l)
 {
  printf("-1");
 }
 else
 {
  printf("%d %d %d",a,b,c);
 }
    return 0;
}
