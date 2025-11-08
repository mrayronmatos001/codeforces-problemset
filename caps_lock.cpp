#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    // Conta quantas letras maiúsculas tem (exceto a primeira)
    int maiusculas = 0;
    for (int i = 1; i < s.length(); i++) {
        if (isupper(s[i])) {
            maiusculas++;
        }
    }
    
    // Verifica se deve inverter:
    // 1. Todas as letras são maiúsculas
    // 2. Todas exceto a primeira são maiúsculas
    bool inverter = false;
    
    if (isupper(s[0]) && maiusculas == s.length() - 1) {
        // Caso 1: todas maiúsculas (ex: "CAPS")
        inverter = true;
    } else if (islower(s[0]) && maiusculas == s.length() - 1) {
        // Caso 2: primeira minúscula, resto maiúscula (ex: "cAPS")
        inverter = true;
    }
    
    // Inverte o case se necessário
    if (inverter) {
        for (int i = 0; i < s.length(); i++) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s[i] = toupper(s[i]);
            }
        }
    }
    
    cout << s << endl;
}