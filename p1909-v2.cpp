// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int pen,a1,b1,c1,a2,b2,c2,a3,b3,c3,ans;
 scanf("%d%d%d%d%d%d%d",&pen,&a1,&a2,&b1,&b2,&c1,&c2);
 if(pen%a1==0)
 {
     a3=a2*(pen/a1);
 }
 else
 {
     a3=a2*(pen/a1+1); 
 }
 if(pen%b1==0)
 {
     b3=b2*(pen/a1);
 }
 else
 {
     b3=b2*(pen/b1+1); 
 }
 if(pen%c1==0)
 {
     c3=c2*(pen/c1);
 }
 else
 {
     c3=c2*(pen/c1+1); 
 }
 if(a3<b3)
 {
     ans=a3;
 }
 else
 {
     ans=b3;
 }
 if(c3<ans)
 {
     ans=c3;
 }
 printf("%d",ans);
 return 0;    
} 
