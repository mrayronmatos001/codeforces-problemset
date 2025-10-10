#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    char aux;
    string s;
    cin >> n >> t;
    cin >> s;

    for (int i=0; i<t; i++) {
        for (int j=0;j<s.length()-1;j++) {
            if (s[j]<s[j+1]) {
                swap(s[j],s[j+1]);
                j++;
            }
        }
    }

    cout << s << endl;
}