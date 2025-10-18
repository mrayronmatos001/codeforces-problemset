#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,l,r,t=0;
    cin >> n >> l >> r;
    vector<int> v(n);
    vector<int> soma(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n;i++) {
        t+=v[i];
        soma[i]=t;
    }
    if (l==1) {
        cout << (soma[r-1]-0) << endl;
    } else {
       cout << (soma[r-1]-soma[l-2]) << endl; 
    }
    
}   