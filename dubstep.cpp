#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    // Substitui todos "WUB" por espaço
    while (s.find("WUB") != string::npos) {
        s.replace(s.find("WUB"), 3, " ");
    }
    
    // Imprime removendo espaços duplicados
    bool first = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            cout << s[i];
            first = false;
        } else if (i + 1 < s.length() && s[i + 1] != ' ' && !first) {
            cout << " ";
        }
    }
    cout << endl;
}