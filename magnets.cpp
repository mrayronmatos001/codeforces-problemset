#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=1;
    cin >> n;
    vector<int> mags(n);
    for (int i=0; i<n; i++) {
        cin >> mags[i];
    }

    for (int i=0; i<(n-1); i++) {
        if (mags[i]!=mags[i+1]) {
            c++;
        }
    }

    cout << c << endl;
    return 0;
}