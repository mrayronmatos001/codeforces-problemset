#include <bits/stdc++.h>
using namespace std;

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    fast_io();

    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "NO" << endl;
        return 0;
    }

    int last_pos = s.length()-1;
    for (int i=0;i<s.length();i++) {
        if (s[i]!=(t[last_pos-i])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}