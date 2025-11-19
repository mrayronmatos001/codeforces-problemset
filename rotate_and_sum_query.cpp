#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> b(2 * n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        b[i + n] = a[i];
    }
    
    for (int i = 2 * n - 1; i > 0; i--) {
        b[i - 1] += b[i];  
    }
    
    int rui_c = 0;
    while(q--) { 
        int cmd;
        cin >> cmd;
        
        if (cmd == 1) {
            int c;
            cin >> c;
            rui_c += c;
            rui_c %= n;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << (b[l + rui_c] - b[r + rui_c]) << "\n";
        }
    }
    
    return 0;
}