#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,h,a;
    cin >> n >> h;
    
    int width = n;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > h) {
            width++;
        }
    }
    
    cout << width << endl;
    
    return 0;
}