#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // Declaração das variáveis principais:
    // n = número de pessoas ao redor do lago
    // c = limite de pessoas que Takahashi precisa encontrar antes de parar
    // m = circunferência do lago (comprimento total do círculo)
    int n, c; 
    ll m;
    cin >> n >> m >> c;
    
    // Vetor para armazenar as posições das n pessoas ao redor do lago
    // Cada posição é uma distância no sentido horário a partir do ponto 0
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    // Ordena as posições em ordem crescente (0 até m-1)
    // Isso facilita o processamento sequencial das posições
    sort(a.begin(), a.end());
    
    // TRUQUE PRINCIPAL: Duplicação do círculo
    // Para cada posição original, adiciona uma cópia com +m
    // Exemplo: se temos posições [1, 3, 5] com m=6
    // Após duplicação: [1, 3, 5, 7, 9, 11]
    // Isso simula o movimento circular - quando passamos de m, voltamos ao início
    rep(i, n) a.push_back(a[i]+m);
    
    // Adiciona um marcador final em 2*m (duas voltas completas)
    // Serve como sentinela para evitar acessos fora dos limites
    a.push_back(m*2);
    
    // px = "posição anterior" - inicializa com a última pessoa "virtual" 
    // (última pessoa original menos uma volta completa)
    // Isso é necessário para calcular a distância do início (posição 0)
    ll px = a[n-1]-m;
    
    // r = ponteiro direito para a técnica de janela deslizante
    // Indica até onde Takahashi consegue chegar partindo da posição l
    int r = 0;
    
    // ans = acumulador da resposta final (soma de todos os X_i)
    ll ans = 0;
    
    // Loop principal: para cada possível posição inicial i (0 até M-1)
    // l representa o índice da primeira pessoa que Takahashi encontra
    rep(l, n) {
        // Expande a janela para a direita enquanto:
        // 1. Não encontramos c pessoas ainda (r-l < c), OU
        // 2. A pessoa atual está na mesma posição que a anterior (a[r-1] == a[r])
        //    (precisamos incluir todas as pessoas na mesma posição)
        while (r-l < c or a[r-1] == a[r]) r++;
        
        // Calcula a contribuição para a resposta:
        // (a[l]-px) = quantas posições iniciais existem entre px e a[l]
        //             (todas as posições onde Takahashi começa e encontra 
        //              as mesmas r-l pessoas)
        // (r-l) = número de pessoas que Takahashi encontra (X_i)
        // Multiplica: cada uma dessas posições iniciais contribui com (r-l) para a soma
        ans += (a[l]-px)*(r-l);
        
        // Atualiza px para a posição atual
        // Na próxima iteração, calcularemos a distância a partir deste ponto
        px = a[l];
    }
    
    // Imprime a resposta final: soma de todos os X_i para i de 0 até M-1
    cout << ans << '\n';
    
    return 0;
}