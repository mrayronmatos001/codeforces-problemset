#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int k,l,m,n,d;

    cin >> k >> l >> m >> n >> d;
    set<int> damanged_dragons;
    for (int i=1; i<=d; i++) {
        if (i%k==0||i%l==0||i%m==0||i%n==0) {
            damanged_dragons.insert(i);
        }
    }

    cout << damanged_dragons.size() << endl;
}