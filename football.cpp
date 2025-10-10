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

    string s;
    int c=0;
    cin >> s;

    for (int i=0; i<s.length(); i++) {
        if (s[i]==s[i+1]) {
            c++;
        } else {
            c=0;
        }
        if (c==6) {
            cout << "YES" << endl;
            return 0;
        }
            
    }

    cout << "NO" << endl;
    return 0;
}