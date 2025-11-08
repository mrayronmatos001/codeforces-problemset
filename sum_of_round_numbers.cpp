#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> rounds;
        int potencia = 1;
        
        while (n > 0) {
            int digito = n % 10;
            if (digito != 0) {
                rounds.push_back(digito * potencia);
            }
            n /= 10;
            potencia *= 10;
        }
        
        cout << rounds.size() << endl;
        for (int num : rounds) {
            cout << num << " ";
        }
        cout << endl;
    }
}