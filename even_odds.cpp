#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long limit = ((n+1)/2);
    if (k>limit) {
        k-=limit;
        cout << (2*k) << endl;
        return 0;
    } else {
        cout << (2*k-1) << endl;
        return 0;
    }
}