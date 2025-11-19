#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c=0, c2=0;
    cin >> n;
    for (int i=0;i<n;i++) {
        int value;
        cin >> value;
        if (value>10)value=10;
        if (value != -1) {
            c2 += value;
        } else if (value == -1 && c2 == 0) {
            c++;
        } else if (value == -1) {
            c2--;
        }
    }
    cout << c << endl;
}