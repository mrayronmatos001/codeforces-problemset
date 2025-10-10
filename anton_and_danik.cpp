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

    int n,a,d,middle;
    string s;
    cin >> n >> s;
    a = d = 0;
    middle = (n+2)/2;
    for (char letter : s) {
        if (letter == 'D') {
            d++;
        } else {
            a++;
        }
        if(d>=middle) {
            cout << "Danik" << endl;
            return 0;
        } else if (a>=middle) {
            cout << "Anton" << endl;
            return 0;
        }
    }

    cout << "Friendship" << endl;
    return 0;
}