#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,t=0, mx=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a >> b;
        t+=(b-a);
        mx=max(mx,t);
    }

    cout << mx << endl;
    return 0;
}