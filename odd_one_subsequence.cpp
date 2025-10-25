#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        freq[value]++;
    }
    
    long long total = 0;  // MUDANÇA CRUCIAL: usar long long
    
    for (auto &[key, val] : freq) {
        if (val > 1) {
            // Calcular C(val, 2) = número de pares
            long long pares = (long long)val * (val - 1) / 2;
            
            // Número de elementos diferentes
            long long diferentes = N - val;
            
            // Adicionar contribuição
            total += pares * diferentes;
        }
    }
    
    cout << total << endl;
    return 0;
}