#include<bits/stdc++.h>
using namespace std;
quene <int> x;
quene <int> y;
quene <int> yin;
quene <int> shun;

int a[360][360],c1,c2,d,n,m; 
int dfs(int xx,int yy,int nn);
{
 if(nn!=0)
 {
  dfs(xx+1,yy,nn-1);
  dfs(xx,yy+1,nn-1);
  dfs(xx,yy-1,nn-1);
  dfs(xx-1,yy,nn-1);
 }
 if(aa[xx][yy]==0)
 {
  aa[xx][yy]=-1;
 }
}
int bfs(int xx,int yy)
{
 
}
int main()
{
    //freopen("bandit.in","r",stdin);
 //freopen("bandit.out","w",stdout);
 int xx,yy,i,j;
 scanf("%d %d %d %d %d",&n,&m,&c1,&c2,&d);
 for(i=0;i<n;i++)
 {
  for(j=0;j<m*2;j++)
  {
   char aa;
   scanf("%c",&aa);
   if(aa=='.')
   {
    a[i][j]=0;
   }
   else if(aa>=1&&aa<=9)
   {
    int y=0;
    for(;aa>=0&&aa<=9;)
    {
     y=aa-'0'+y;
     scanf("%c",&aa);
    }
    a[i][j]=y;
    dfs(i,j,a[i][j]);
   }
   else if(aa=='S')
   {
    xx=i;
    yy=j;
   }
   else if(aa=='T')
   {
    a[i][j]=1000;
   }
  }
 }
 bfs()
    return 0;
}
