#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    
    int maxi = 0;
    
    maxi = max(maxi, a + b + c); 
    maxi = max(maxi, a + b * c);
    maxi = max(maxi, a * b + c);
    maxi = max(maxi, a * b * c);
    maxi = max(maxi, (a + b) * c);
    maxi = max(maxi, a * (b + c));
    
    cout << maxi << endl;
    return 0;
}