#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> teams(n,vector<int>(2));
    for (int i=0;i<n;i++) {
        cin >> teams[i][0] >> teams[i][1];
    }
    int c=0;
    for (int i=0;i<n;i++) {
        for(int j=0; j<n;j++) {
            if (i==j) continue;
            if(teams[i][0]==teams[j][1]) c++;
        }
    }
    cout << c << endl;
}