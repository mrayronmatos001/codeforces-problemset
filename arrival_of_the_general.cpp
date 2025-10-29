#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n,maxi=0,mini=101,i_max,i_min, result;
    cin >> n;
    vector<int> seq(n);
    for (int i=0; i<n; i++) {
        cin >> seq[i];
        if (maxi<seq[i]) {
            maxi=seq[i];
            i_max=i;
        } 
    }
    for (int i=seq.size()-1;i>=0;i--) {
        if (mini>seq[i]) {
            mini=seq[i];
            i_min=i;
        }
    }
    if (i_max>i_min) {
        result=(i_max+(n-1-i_min)) - 1;
    } else {
        result=(i_max+(n-1-i_min));
    }
    cout << result << endl;
}