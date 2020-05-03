#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int y,x1,x2;
}a[1001];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++)
        scanf("%d%d%d",&a[i].y,&a[i].x1,&a[i].x2);
    for(int i = 1;i <= n;i++)
    {
        int y = a[i].y,x1 = a[i].x1,x2 = a[i].x2;  
        int h1 = 0,h2 = 0;
        for(int j = 1;j <= n;j++)
        {
            if(i == j) 
                continue;
            if(a[j].y >= y) 
                continue;
            if(a[j].x2 > x1 && a[j].x1 <= x1)
                h1 = max(h1,a[j].y);
            if(a[j].x2 >= x2 && a[j].x1 < x2)
                h2 = max(h2,a[j].y);
        }
    //  printf("%d %d %d %d %d %d^^\n",y,a[i].x1,a[i].x2,i,h1,h2); //????
        ans += y * 2 - h1 - h2;
    }
    cout << ans;
    return 0;
 } 
