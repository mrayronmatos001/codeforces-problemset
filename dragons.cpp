#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long s;
    int n;
    cin >> s >> n;
    vector<pair<int,int>> dragons;
    
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        dragons.push_back({x, y});
    }
    
    sort(dragons.begin(),dragons.end());
    
    for (int i=0;i<n;i++) {
        if (s > dragons[i].first) {
            s+=dragons[i].second;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}