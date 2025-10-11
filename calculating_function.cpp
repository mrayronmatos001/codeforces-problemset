#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    cin >> n;
    
    long long result;
    
    if (n % 2 == 0) {
        result = n / 2;
    } else {
        result = -(n + 1) / 2;
    }
    
    cout << result << '\n';
    
    return 0;
}
