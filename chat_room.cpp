#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    string target = "hello";
    int j = 0;
    
    for (int i = 0; i < s.length() && j < target.length(); i++) {
        if (s[i] == target[j]) {
            j++;
        }
    }
    
    if (j == target.length()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
