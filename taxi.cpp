#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int count[5] = {0}; // count[i] = quantos grupos de tamanho i
    
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        count[s]++;
    }
    
    int taxis = 0;
    
    // Grupos de 4 → um táxi cada
    taxis += count[4];
    
    // Grupos de 3 + grupos de 1
    int pairs_3_1 = min(count[3], count[1]);
    taxis += pairs_3_1;
    count[3] -= pairs_3_1;
    count[1] -= pairs_3_1;
    
    // Grupos de 3 restantes → um táxi cada
    taxis += count[3];
    
    // Grupos de 2 + grupos de 2
    taxis += count[2] / 2;
    count[2] %= 2;
    
    // Grupo de 2 restante + dois grupos de 1
    if (count[2] == 1) {
        taxis++;
        count[1] -= min(count[1], 2);
    }
    
    // Grupos de 1 restantes
    taxis += (count[1] + 3) / 4; // Arredonda para cima
    
    cout << taxis << endl;
}