#include <bits/stdc++.h>
using namespace std;

int N, M, K;
string S;
vector<vector<int>> adj;
map<pair<int, int>, int> memo;

// Retorna: 1 se Alice ganha, 0 se Bob ganha
// v = vértice atual, moves = movimentos restantes
int solve(int v, int moves) {
    // Caso base: sem mais movimentos
    if (moves == 0) {
        return (S[v] == 'A') ? 1 : 0;
    }
    
    // Verificar memoização
    pair<int, int> state = {v, moves};
    if (memo.count(state)) {
        return memo[state];
    }
    
    // Determinar de quem é a vez
    // Total de movimentos = 2K
    // Movimentos já feitos = 2K - moves
    // Se par, é turno de Alice; se ímpar, turno de Bob
    int moves_done = 2 * K - moves;
    bool alice_turn = (moves_done % 2 == 0);
    
    int result;
    
    if (alice_turn) {
        // Alice quer encontrar ALGUM movimento que leve à sua vitória
        result = 0; // Assume Bob ganha por padrão
        for (int next : adj[v]) {
            if (solve(next, moves - 1) == 1) {
                result = 1; // Alice encontrou um caminho vencedor
                break;
            }
        }
    } else {
        // Bob quer encontrar ALGUM movimento que leve à sua vitória
        result = 1; // Assume Alice ganha por padrão
        for (int next : adj[v]) {
            if (solve(next, moves - 1) == 0) {
                result = 0; // Bob encontrou um caminho vencedor
                break;
            }
        }
    }
    
    memo[state] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> N >> M >> K;
        cin >> S;
        
        // Ajustar string para indexação 1-based
        S = " " + S;
        
        adj.assign(N + 1, vector<int>());
        memo.clear();
        
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        // Começar do vértice 1 com 2K movimentos
        int winner = solve(1, 2 * K);
        
        if (winner == 1) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    
    return 0;
}