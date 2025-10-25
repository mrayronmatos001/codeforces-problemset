#include <iostream>
using std::cin;
using std::cout;
using std::min;
using std::max;
#include <cmath> // Para a função std::sqrt
    typedef long long int ll;

// Define f(x, y) = z, onde z é o inteiro formado pela concatenação de x e y.
// O problema requer que f(C, C+x) seja um quadrado perfeito, ou seja:
// f(C, C+x) = k^2 para algum inteiro k.

// Função para calcular floor(sqrt(x)) de forma segura.
// A função std::sqrt retorna um double, e a comparação com long long int (ll)
// pode ter imprecisões de ponto flutuante em valores grandes.
ll f (ll x) {
    // 1. Inicia com o valor de sqrt(x) da biblioteca.
    ll y = sqrt(x); 
    
    // 2. Ajuste para trás: Corrige imprecisão se y for ligeiramente maior que a raiz real.
    while (y * y > x) y--; 
    
    // 3. Ajuste para frente: Corrige imprecisão se y for ligeiramente menor que a raiz real.
    // Garante que y é o maior inteiro tal que y^2 <= x.
    while ((y+1) * (y+1) <= x) y++; 
    
    return y; // Retorna floor(sqrt(x))
}

// Função principal de resolução.
ll solve (ll c, ll d) {
    ll ans = 0;
    
    // Variáveis que definem a FAIXA atual para o valor (C + x).
    ll xmin = 1;     // Início da faixa de C+x (e.g., para 1-dígito, xmin=1)
    ll xmax = 9;     // Fim da faixa de C+x (e.g., para 1-dígito, xmax=9)
    
    // cshift: Potência de 10 que representa o deslocamento de C para a concatenação.
    // Ex: Se C=3 e C+x está na faixa [10, 99], cshift será 100.
    // f(3, 14) = 3 * 100 + 14 = 314.
    ll cshift = 10; 

    // O loop itera sobre o NÚMERO DE DÍGITOS de (C + x).
    // O valor máximo de (C + x) é C + D.
    while (xmin <= c + d) { 
        
        // 1. Define o RANGE [l, r] de valores válidos para (C + x).
        
        // l: O valor mínimo possível para (C + x) nesta faixa de dígitos.
        // É o maior entre o início da faixa de dígitos (xmin) e C+1 (pois x >= 1).
        ll l = max(xmin, c + 1); 
        
        // r: O valor máximo possível para (C + x).
        // É o menor entre o fim da faixa de dígitos (xmax) e C+D (limite imposto pelo problema).
        ll r = min(xmax, c + d); 
        
        // Se a faixa [l, r] for válida (l <= r), há valores de C+x a serem verificados.
        if (l <= r) {
            
            // 2. Calcula os valores de concatenação (f(C, C+x)) nos limites da faixa [l, r].
            
            // vl: O menor valor de f(C, C+x) nesta faixa.
            // É a concatenação de C e l: C * cshift + l
            ll vl = c * cshift + l; 
            
            // vr: O maior valor de f(C, C+x) nesta faixa.
            // É a concatenação de C e r: C * cshift + r
            ll vr = c * cshift + r; 
            
            // 3. O PULO DO GATO (Inclusão-Exclusão com Raízes):
            // O número de quadrados perfeitos (k^2) no intervalo [vl, vr] é dado por:
            // floor(sqrt(vr)) - floor(sqrt(vl - 1)).
            // Isto é: (k_max) - (k_min - 1).
            // k_max é o maior inteiro k tal que k^2 <= vr.
            // k_min é o menor inteiro k tal que k^2 >= vl.
            ll k_max = f(vr); // k_max: o maior 'k' tal que k^2 <= vr
            ll k_min_minus_1 = f(vl - 1); // k_min-1: o maior 'k' tal que k^2 <= vl - 1
            
            // A diferença nos dá o número exato de quadrados perfeitos no intervalo [vl, vr].
            ll num_squares = k_max - k_min_minus_1;
            
            // Cada quadrado perfeito k^2 que existe neste intervalo corresponde a
            // exatamente um valor (C + x) e, portanto, a exatamente um valor x.
            ans += num_squares; 
        }
        
        // 4. Prepara para a próxima faixa de dígitos:
        // Ex: Se estava em [1, 9] (1 dígito), passa para [10, 99] (2 dígitos).
        xmin = xmin * 10;                // 1 -> 10 -> 100 ...
        xmax = (xmax + 1) * 10 - 1;      // 9 -> 99 -> 999 ...
        cshift *= 10;                    // 10 -> 100 -> 1000 ...
    }
    
    return ans;
}

int main (void) {
    // Configuração inicial para I/O rápida
    cin.tie(0)->sync_with_stdio(0);

    ll T;
    cin >> T;
    for (ll ti = 0; ti < T; ti++) {
        ll c, d;
        cin >> c >> d;
        ll ans = solve(c, d);
        cout << ans << "\n";
    }
    
    return 0;
}