#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string p;
    std::cin >> p;

    // Itera pela string de entrada
    for (int i = 0; i < p.length(); i++) {
        // Verifica APENAS os caracteres que produzem saída
        if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9') {
            std::cout << "YES" << std::endl;
            return 0; // Encontrou um, então pode parar e sair
        }
    }

    // Se o loop terminar sem encontrar H, Q ou 9, então não há saída.
    std::cout << "NO" << std::endl;
    
    return 0;
}
