#include <iostream>
#include <vector>
#include <algorithm> // Necessário para 'min' e 'max' se você usar '<bits/stdc++.h>' ou 'std::min' diretamente.
using namespace std; 
// O cabeçalho '<bits/stdc++.h>' engloba todos esses.

int main() {
    // Acelera a entrada/saída (cin/cout) para que o código seja mais rápido,
    // o que é crucial em problemas de programação competitiva com muitos dados.
    cin.tie(0)->sync_with_stdio(0); 

    int Q;
    // 'Q' é o número total de comandos (operações de consulta, inserção ou remoção).
    cin >> Q; 

    // O coração da solução: dois vetores que funcionam como pilhas de estado.

    // A: Rastreia o nível de balanceamento atual da string de parênteses.
    // 'A[i]' é o 'nível de profundidade' do prefixo da string até o elemento 'i'.
    // '{0}' Inicializa o vetor com um único elemento '0', representando o nível de balanceamento inicial 
    // de uma string vazia.
    vector<int> A{0}; 

    // B: Rastreia o MÍNIMO nível de balanceamento encontrado em todo o prefixo.
    // Usado para garantir que nunca tenhamos parênteses fechados sem um aberto correspondente.
    // '{0}' Inicializa com '0', pois o mínimo de uma string vazia é 0.
    vector<int> B{0}; 
    
    // O loop processa cada um dos Q comandos.
    for (int q = 1; q <= Q; q++) {
        int cmd;
        cin >> cmd; // Lê o tipo de comando: 1 (inserir) ou 2 (remover).

        if (cmd == 1) { // Comando de Inserção (simula a adição de um caractere ao final da string)
            char c;
            cin >> c; // Lê o caractere a ser adicionado ('(' ou ')').

            // 1. Atualiza A (Nível de Balanceamento):
            // O novo nível é o anterior (A.back()) + (1 se for '(' ou -1 se for ')').
            // Essa linha simula adicionar o caractere e recalcular o novo nível total.
            A.push_back(A.back() + (c == '(' ? 1 : -1)); 

            // 2. Atualiza B (Mínimo de Balanceamento até agora):
            // O novo mínimo é o mínimo anterior (B.back()) comparado ao nível atual (A.back()).
            // Isso garante que B sempre armazene a 'queda' mais baixa no balanceamento.
            B.push_back(min(B.back(), A.back())); 

        } else { // Comando de Remoção (simula a remoção do último caractere da string)
            // Simplesmente desfaz as últimas operações, voltando ao estado anterior.
            // É seguro, pois o problema garante que a string nunca fica vazia na remoção (Q >= 1).
            // NOTA: Em código geral, é preciso verificar se o vetor não está vazio (A.size() > 1).
            A.pop_back(); 
            B.pop_back(); 
        }

        // Output: Verifica se a string tem parênteses totalmente balanceados
        // (ela forma uma 'árvore' que começa e termina no nível 0, sem descer abaixo de 0).

        cout << (
            // Condição 1: A.back() == 0 
            // Garante que o número total de '(' é igual ao número total de ')' no final.
            A.back() == 0 
            
            // operador lógico AND (e)
            and 
            
            // Condição 2: B.back() == 0 
            // Garante que o balanceamento nunca caiu abaixo de zero em NENHUM PONTO da string.
            // Se B.back() fosse -1, significaria que em algum momento tivemos ')(' (desbalanceado).
            B.back() == 0 
            
            // Se ambas as condições forem verdadeiras, imprime "Yes", caso contrário, "No".
            ? "Yes" : "No") << "\n";
    }
    return 0;
}