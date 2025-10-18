#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    using namespace std;
    
    unsigned N, M;
    cin >> N >> M;
    
    vector<unsigned> A(N);
    for (auto&& a : A) {
        cin >> a;
    }
    
    // ============================================================
    // Função: Enumera todas as somas de subsequências válidas
    // (sem elementos adjacentes) de uma sequência
    // ============================================================
    // Retorna par:
    //   - used: somas onde o ÚLTIMO elemento FOI incluído
    //   - all: TODAS as somas (incluiu ou não o último)
    // ============================================================
    const auto solve = [M](const auto& seq) -> pair<vector<unsigned>, vector<unsigned>> {
        vector<unsigned> used;    // Subsequências que USARAM o último elemento processado
        vector<unsigned> unused;  // Subsequências que NÃO USARAM o último elemento
        
        // Base: subsequência vazia tem soma 0
        unused.emplace_back(0);
        
        // Processar cada elemento da sequência
        for (const auto x : seq) {
            // SWAP: o que estava em "used" passa para "unused"
            // Isso porque agora vamos processar um novo elemento,
            // então o "último" anterior não é mais o último
            swap(used, unused);
            
            // Para cada soma anterior (agora em "used"):
            for (auto&& v : used) {
                // Opção 1: NÃO incluir elemento atual
                // (mantém a soma original)
                unused.emplace_back(v);
                
                // Opção 2: INCLUIR elemento atual
                // (adiciona x e atualiza mod M)
                // Modifica in-place para economizar memória
                (v += x) %= M;
            }
            // Após o loop:
            // - "used" contém somas que INCLUEM x
            // - "unused" contém somas que NÃO INCLUEM x
        }
        
        // Criar vetor com TODAS as somas (used + unused)
        vector<unsigned> all(used);
        ranges::copy(unused, back_inserter(all));
        
        // Ordenar para facilitar busca binária
        ranges::sort(used);
        ranges::sort(all);
        
        return make_pair(used, all);
    };
    
    // ============================================================
    // PASSO 1: Processar primeira metade do array
    // ============================================================
    // Usando C++20 ranges: A | views::take(N/2)
    // Pega os primeiros N/2 elementos
    const auto [first_used, first_all] = solve(A | views::take(N / 2));
    
    // ============================================================
    // PASSO 2: Processar segunda metade INVERTIDA
    // ============================================================
    // A | views::reverse | views::take((N+1)/2)
    // Inverte o array e pega os primeiros (N+1)/2 elementos
    // Isso é equivalente a pegar os últimos (N+1)/2 elementos invertidos
    const auto [second_used, second_all] = solve(A | views::reverse | views::take((N + 1) / 2));
    
    // ============================================================
    // PASSO 3: Contar combinações usando INCLUSÃO-EXCLUSÃO
    // ============================================================
    // Estratégia:
    //   1. Contar TODAS as combinações válidas (superestimativa)
    //   2. Subtrair combinações INVÁLIDAS (ambos lados usam último)
    // ============================================================
    
    unsigned long ans = 0;
    
    // ──────────────────────────────────────────────────────────
    // ETAPA 1: Contar TODAS as combinações
    // ──────────────────────────────────────────────────────────
    // Para cada soma 'a' da primeira metade:
    for (const auto a : first_all) {
        // Procurar complemento (M - a) % M na segunda metade
        // Queremos: (a + b) ≡ 0 (mod M)
        // Então: b ≡ -a ≡ M - a (mod M)
        unsigned target = (M - a) % M;
        
        // Usar busca binária para contar quantas vezes 'target' aparece
        // lower_bound: primeiro elemento >= target
        // upper_bound: primeiro elemento > target
        // Diferença = quantidade de elementos iguais a target
        auto lower = ranges::lower_bound(second_all, target);
        auto upper = ranges::upper_bound(second_all, target);
        ans += upper - lower;
    }
    
    // ──────────────────────────────────────────────────────────
    // ETAPA 2: Subtrair combinações INVÁLIDAS
    // ──────────────────────────────────────────────────────────
    // Problema: se ambas as metades USARAM o último elemento,
    // esses elementos são ADJACENTES no array original!
    // (lembre-se: a segunda metade está invertida)
    //
    // Exemplo: A = [1, 2 | 3, 4]
    // Primeira metade usa 2 (último)
    // Segunda metade invertida [4, 3] usa 3 (último da invertida)
    // No array original, 2 e 3 são adjacentes! ❌
    // ──────────────────────────────────────────────────────────
    
    for (const auto a : first_used) {
        unsigned target = (M - a) % M;
        
        auto lower = ranges::lower_bound(second_used, target);
        auto upper = ranges::upper_bound(second_used, target);
        ans -= upper - lower;
    }
    
    cout << ans << endl;
    
    return 0;
}