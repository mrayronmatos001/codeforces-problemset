#include <bits/stdc++.h>
using namespace std;

// Define 'll' como long long int para suportar grandes coordenadas (até 10^9) e deslocamentos.
typedef long long int ll;

// N: Número de intervalos (1 a N).
// Q: Número de consultas.
ll n, q;

// W: Vetor armazena as larguras originais dos N intervalos: W[i] é a largura do Intervalo i+1.
// Nota: O problema usa índices 1 a N, o código usa 0 a N-1.
vector<ll> w;

// Estrutura para representar um "bloco" de intervalos que foram alinhados juntos.
// O vetor 'bar' (barra) é uma pilha desses blocos.
typedef struct {
    ll li;      // Índice do primeiro intervalo afetado (intervalo esquerdo, de 0 a N-1).
    ll ri;      // Índice do último intervalo afetado (intervalo direito, de 0 a N-1).
    ll gravity; // Direção do alinhamento: -1 para alinhamento à esquerda (Type 1), +1 para alinhamento à direita (Type 2).
    ll x;       // Coordenada de referência. Se gravity é -1, 'x' é o ponto esquerdo (l). Se gravity é +1, 'x' é o ponto direito (r).
} Block;

// 'bar' armazena a história das translações de prefixo.
// O topo da pilha (bar.back()) representa a translação mais recente e dominante.
vector<Block> bar;

// Função auxiliar para processar as consultas Tipo 1 e Tipo 2 (translações/alinhamentos).
// v: Índice do intervalo de referência (0 a N-1).
// dir: -1 para Tipo 1 (alinhar pelo ponto esquerdo), +1 para Tipo 2 (alinhar pelo ponto direito).
void barclear (ll v, ll dir) {
    while (true) {
        // Pega o bloco de alinhamento mais recente no topo da pilha.
        Block b = bar.back();
        bar.pop_back();

        // Se o bloco atual afeta o intervalo de referência 'v' (v <= b.ri):
        if (b.ri >= v) {
            // Se o bloco 'b' se estende além de 'v', ele precisa ser dividido (o restante não é afetado pela nova translação).
            // Exemplo: Se 'b' alinha [0, 9] e a nova consulta afeta [0, 4] (v=4).
            // O bloco [5, 9] mantém o alinhamento de 'b'.
            if (v + 1 <= b.ri) {
                bar.push_back({v + 1, b.ri, b.gravity, b.x});
            }

            // --- Cálculo das Coordenadas do Ponto de Alinhamento (l_v ou r_v) ---
            ll fl, fr; // fl: left endpoint, fr: right endpoint.
            
            // Reconstroi as coordenadas do intervalo 'v' usando o bloco 'b' (o último alinhamento que o afetou).
            if (b.gravity < 0) { // O bloco 'b' foi um alinhamento à esquerda (Type 1).
                fl = b.x;         // O ponto esquerdo (l_v) é a coordenada de referência 'x' desse bloco.
                fr = fl + w[v];   // O ponto direito (r_v) é l_v + W_v.
            } else {             // O bloco 'b' foi um alinhamento à direita (Type 2).
                fr = b.x;         // O ponto direito (r_v) é a coordenada de referência 'x' desse bloco.
                fl = fr - w[v];   // O ponto esquerdo (l_v) é r_v - W_v.
            }
            // -----------------------------------------------------------------

            // Agora, aplica a nova translação:
            // Define o novo ponto de alinhamento (currx).
            ll currx = ((dir < 0) ? fl : fr); // Se Type 1 (dir=-1), o ponto de alinhamento é o ponto esquerdo (fl). Se Type 2 (dir=+1), é o ponto direito (fr).

            // Adiciona o novo bloco de alinhamento no topo da pilha 'bar'.
            // Este bloco afeta o prefixo [0, v] e define o novo 'gravity' e a nova 'x' de referência.
            bar.push_back({0, v, dir, currx});
            break; // A translação está completa.
        }
    }
}

int main (void) {
    // Leitura da entrada N
    cin >> n;
    w.resize(n);
    // Leitura das larguras W_1 a W_N (armazenadas em w[0] a w[n-1]).
    for (ll i = 0; i < n; i++) {
        cin >> w[i];
    }

    // init: Configuração inicial dos intervalos.
    // Inicialmente, todos os intervalos [0, N-1] estão em [0, W_i].
    // O bloco inicial é: li=0, ri=n-1, gravity=-1 (Type 1), x=0 (ponto esquerdo em 0).
    bar.push_back({0, n - 1, -1, 0});

    // Leitura do número de consultas Q.
    cin >> q;
    
    // Processamento das Q consultas.
    for (ll qi = 0; qi < q; qi++) {
        ll type;
        cin >> type;
        
        // --- Tipo 1: Alinhamento à Esquerda ---
        if (type == 1) {
            ll v;
            cin >> v;
            --v; // Converte o índice 1-based do problema para o índice 0-based do vetor.
            barclear(v, -1);
            
        // --- Tipo 2: Alinhamento à Direita ---
        } else if (type == 2) {
            ll v;
            cin >> v;
            --v; // Converte o índice 1-based do problema para o índice 0-based do vetor.
            barclear(v, +1);
            
        // --- Tipo 3: Consulta de Contagem ---
        } else if (type == 3) {
            ll x; // Coordenada x, procuramos x + 1/2.
            cin >> x;
            
            ll ans;
            ll idx; // Índice do bloco em 'bar' que contém o intervalo I_k que por sua vez contém x + 1/2.
            
            // 1. Busca Binária para encontrar o bloco 'idx' que contém a coordenada 'x' para algum intervalo.
            {
                ll ok = -1, ng = bar.size();
                while (ok + 1 < ng) {
                    ll med = (ok + ng) / 2;
                    ll fl, fr; // fl: left endpoint, fr: right endpoint.

                    // Calcula os pontos finais do **último intervalo do bloco** (bar[med].ri).
                    if (bar[med].gravity < 0) {
                        fl = bar[med].x;
                        fr = fl + w[bar[med].ri];
                    } else {
                        fr = bar[med].x;
                        fl = fr - w[bar[med].ri];
                    }

                    // Verifica se o intervalo (no índice bar[med].ri) pode conter x + 1/2.
                    // A condição l <= x + 1/2 <= r é traduzida para inteiros como l <= x E x < r.
                    if (fl <= x && x < fr) {
                        ok = med; // O bloco pode estar aqui.
                    } else {
                        ng = med; // O bloco está em um índice menor.
                    }
                }
                idx = ok; // 'idx' é o bloco onde a contagem pode começar.
            }

            if (idx < 0) {
                // Se nenhum bloco foi encontrado, nenhum intervalo contém x + 1/2.
                ans = 0;
            } else {
                // 2. Busca Binária no **intervalo de índices** ([li, ri]) dentro do bloco 'idx'.
                ll fl, fr;
                ll ok = bar[idx].ri, ng = bar[idx].li - 1; // ok: maior índice de intervalo que contem x+1/2 (inicializado para o maior possível no bloco). ng: menor índice que NÃO contem x+1/2.
                
                // Objetivo: Encontrar o menor índice 'k' (ok) tal que o Intervalo k (e todos i > k) contenham x + 1/2.
                while (ng + 1 < ok) {
                    ll med = (ok + ng) / 2; // Índice do intervalo atual.
                    
                    // Calcula os pontos finais do Intervalo 'med' usando o alinhamento do bloco 'idx'.
                    if (bar[idx].gravity < 0) {
                        fl = bar[idx].x;
                        fr = fl + w[med]; // Largura W[med]
                    } else {
                        fr = bar[idx].x;
                        fl = fr - w[med]; // Largura W[med]
                    }
                    
                    // Verifica se o Intervalo 'med' contém x + 1/2 (l <= x E x < r).
                    if (fl <= x && x < fr) {
                        ok = med; // Intervalo 'med' contém x + 1/2 (o índice de resposta é 'ok' ou menor).
                    } else {
                        ng = med; // Intervalo 'med' NÃO contém x + 1/2 (o índice de resposta é 'ng' ou maior).
                    }
                }
                
                // O resultado da busca é o menor índice (ok) de intervalo que contém x + 1/2.
                // Como os W_i são crescentes (W_1 < W_2 < ...), se o intervalo 'k' contém x + 1/2,
                // todos os intervalos i > k (que são mais largos) também o conterão.
                // A resposta é o número de intervalos de 'ok' até N-1 (total: N - ok).
                ans = n - ok;
            }
            
            // Imprime o resultado.
            cout << ans << "\n";
        }
    }
    
    return 0;
}