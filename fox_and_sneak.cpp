#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Linhas pares: tudo '#'
            cout << string(m, '#') << endl;
        } else {
            // Linhas ímpares: alterna entre '#' no início ou no fim
            if ((i / 2) % 2 == 0) {
                cout << string(m - 1, '.') << '#' << endl;
            } else {
                cout << '#' << string(m - 1, '.') << endl;
            }
        }
    }
}