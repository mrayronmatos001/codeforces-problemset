#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    
    set<int> distinct_colors;
    distinct_colors.insert(s1);
    distinct_colors.insert(s2);
    distinct_colors.insert(s3);
    distinct_colors.insert(s4);
    
    int colors_he_has = distinct_colors.size();
    int need_to_buy = 4 - colors_he_has;
    
    cout << need_to_buy << '\n';
    
    return 0;
}