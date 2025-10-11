#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sum += p;
    }
    
    double result = sum / n;
    
    cout << fixed << setprecision(12) << result << '\n';
    
    return 0;
}