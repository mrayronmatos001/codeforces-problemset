#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s, song;
    bool hasWub=true;
    cin >> s;

    while(hasWub) {
        hasWub=false;
        int c=1;
        for( int i=0; i<s.length(); i++) {
            if (s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
                s=s.substr(3);
                hasWub=true;
                break;
            } else if(s[i+1]=='W' && s[i+2]=='U' && s[i+3]=='B') {
                song+=s.substr(0,c);
                song+=' ';
                s=s.substr(c);
                hasWub=true;
                break;
            }
            c++;
        }
    }

    cout << song << endl;
}