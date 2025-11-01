#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> evens, odds;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }
    
    cout << (evens.size() == 1 ? evens[0] : odds[0]) << endl;
}