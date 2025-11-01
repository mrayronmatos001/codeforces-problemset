#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    map<string,int> db;
    
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (db[s]==0) {
            cout << "OK" << endl;
        } else {
            cout << s << db[s] << endl;
        }
        db[s]+=1;
    }
}