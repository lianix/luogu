#include<bits/stdc++.h>
using namespace std;

int n, a, sum;
int min_sum = 0;
int ans = -0x7f7f7f7f;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    
    cout << ans;
    return 0;
}

