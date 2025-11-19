#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    
    sort(f.begin(), f.end());
    
    int best = INT_MAX;
    for (int k = 0; k <= m - n; k++) {
        int diff = f[k + n - 1] - f[k];
        best = min(best, diff);
    }
    
    cout << best << endl;
    
    return 0;
}