#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Cria um set com todas as letras minúsculas da string
    set<char> letras;
    for(char c : s) {
        letras.insert(tolower(c));
    }
    
    // Um pangram tem exatamente 26 letras diferentes (a-z)
    cout << (letras.size() == 26 ? "YES" : "NO") << endl;
    
    return 0;
}