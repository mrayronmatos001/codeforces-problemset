#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev, cur, maxLen = 1, curLen = 1;
    cin >> n >> prev;
    
    while(--n) {
        cin >> cur;
        curLen = (prev <= cur) ? curLen + 1 : 1;
        maxLen = max(maxLen, curLen);
        prev = cur;
    }
    
    cout << maxLen << '\n';
}