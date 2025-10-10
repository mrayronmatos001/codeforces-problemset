#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,res;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> res;
        if (res) {
            cout << "HARD" << endl;
            return 0;
        }
    }

    cout << "EASY" << endl;
    return 0;
}