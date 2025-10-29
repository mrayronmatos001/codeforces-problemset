#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int c=0;
    while(n>0) {
        if (n>=100) {
            c+=n/100;
            n=n%100;
        } else if (n>=20) {
            c+=n/20;
            n=n%20;
        } else if (n>=10) {
            c+=n/10;
            n=n%10;
        } else if (n>=5) {
            c+=n/5;
            n=n%5;
        } else if (n>=1) {
            c+=n/1;
            n=n%1;
        }
    }
    cout << c << endl;

}