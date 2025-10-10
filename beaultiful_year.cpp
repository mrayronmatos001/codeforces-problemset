#include <bits/stdc++.h>
using namespace std;

inline bool has_distinct_digits(int year) {
    int mask = 0;
    
    while (year > 0) {
        int digit = year % 10;
        int bit = 1 << digit;
        
        if (mask & bit) {
            return false;
        }
        
        mask |= bit;
        year /= 10;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int y;
    cin >> y;
    
    y++;
    
    while (!has_distinct_digits(y)) {
        y++;
    }
    
    cout << y << endl;
    
    return 0;
}