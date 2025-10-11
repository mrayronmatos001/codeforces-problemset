#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int t=0, sum=0,c=0;
    vector<int> coins(n);
    for (int i=0; i<n;i++) {
        cin >> coins[i];
        t+=coins[i];
    }
    
    sort(begin(coins),end(coins),greater<int>());
    
    for (int i=0; i<n; i++) {
        c++;
        sum += coins[i];
        
        if ((t - sum) < sum) {
            break;
        }
    }
    
    cout << c << endl;
    return 0;
}