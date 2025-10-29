#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    
    vector<int> colunas(n);
    
    // Lê a altura de cada coluna
    for(int i = 0; i < n; i++) {
        cin >> colunas[i];
    }
    
    // INSIGHT DO PROBLEMA:
    // Quando a gravidade muda de baixo para direita,
    // os cubos "caem" para a direita e se organizam naturalmente.
    // 
    // O resultado final sempre fica em ordem crescente!
    // 
    // Exemplo:
    // Antes:  [4, 3, 1, 2]
    //         ■
    //         ■ ■
    //         ■ ■   ■
    //         ■ ■ ■ ■
    // 
    // Depois (cubos "caem" para direita e se reorganizam):
    //             ■
    //           ■ ■
    //         ■ ■ ■
    //       ■ ■ ■ ■
    // Resultado: [1, 2, 3, 4]
    
    // Portanto, basta ORDENAR o array!
    sort(colunas.begin(), colunas.end());
    
    // Imprime o resultado
    for(int i = 0; i < n; i++) {
        cout << colunas[i];
        if(i < n-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}