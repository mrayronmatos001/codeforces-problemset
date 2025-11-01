#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    
    // Cumulative sum: conta_a[i] = número de 'a's nos primeiros i caracteres
    vector<int> conta_a(N + 1, 0);
    for (int i = 0; i < N; i++) {
        conta_a[i + 1] = conta_a[i] + (S[i] == 'a' ? 1 : 0);
    }
    
    long long resultado = 0;
    
    // Para cada posição inicial l
    for (int l = 1; l <= N; l++) {
        // Binary search: menor r tal que [l,r] tem A ou mais 'a's
        int left = l, right = N, a_l = N + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (conta_a[mid] - conta_a[l - 1] >= A) {
                a_l = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Binary search: menor r tal que [l,r] tem B ou mais 'b's
        left = l; right = N;
        int b_l = N + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int num_b = (mid - l + 1) - (conta_a[mid] - conta_a[l - 1]);
            if (num_b >= B) {
                b_l = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Conta substrings válidas começando em l
        if (a_l < b_l) {
            resultado += b_l - a_l;
        }
    }
    
    cout << resultado << endl;
}