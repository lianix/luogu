#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    
    cin >> a >> b >> c >> d;
    
    e = c * 60 + d - a * 60 -b;
    f = e % 60;
    e = e / 60;
    
    cout << e << f;
    
    return 0;
}
