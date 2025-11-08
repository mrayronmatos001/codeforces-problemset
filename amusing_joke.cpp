#include <bits/stdc++.h>
using namespace std;

int main()
{
    string first, second;
    map<char,int> man_letters;
    cin >> first >> second;
    
    // Processa primeira string
    for (int i = 0; i < first.length(); i++) {
        man_letters[first[i]]++;
    }
    
    // Processa segunda string
    for (int i = 0; i < second.length(); i++) {
        man_letters[second[i]]++;
    }
    
    string mix;
    cin >> mix;
    map<char,int> mix_letters;
    
    for (int i = 0; i < mix.length(); i++) {
        mix_letters[mix[i]]++;
    }
    
    if (man_letters == mix_letters) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}