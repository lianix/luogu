#include<bits/stdc++.h>
using namespace std;
int banfei;
int a,b,c,d,e;
int main()
{
 //freopen("order.in","r",stdin); 
 //freopen("order.out","w",stdout); 
 scanf("%d",&banfei);
 d=banfei/14;
 e=banfei%14;
 if(e==0)
 {
  a=d;
  b=d;
  c=d;
  printf("%d %d %d",a,b,c);
  return 0;
 }
 while(e!=0)
 {
     for(a=0;a<=e/7;a++)
        {
            for(b=0;b<=e/4;b++)
            {
                for(c=0;c<=e/3;c++)
                {
                    if(a*7+b*4+c*3+d*14==banfei)
                    {
                     a+=d;
                     b+=d;
                     c+=d;
                     printf("%d %d %d",a,b,c);
                     return 0;
        }
                }
            }
        }
        if(d==0)
        {
         printf("-1");
            return 0;
  }
        if(e!=0)
        {
         e+=14;
         d--;
  }
    }
} 
