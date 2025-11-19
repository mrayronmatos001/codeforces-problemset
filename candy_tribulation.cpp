#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long N;
  long long X, Y;
  cin >> N >> X >> Y;
  
  vector<long long> A(N);
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  sort(A.begin(), A.end());
  
  long long mini = A[N-1] * X;  // max(A_i) * X
  long long maxi = A[0] * Y;    // min(A_i) * Y
  
  if (mini > maxi) {
    cout << -1 << endl;
    return 0;
  }
  
  long long total = 0;
  
  for (long long i = 0; i < N; i++) {
    long long numerador = maxi - A[i] * X;
    
    // Verifica se é divisível
    if (numerador % (Y - X) != 0) {
      cout << -1 << endl;
      return 0;
    }
    
    long long grandes = numerador / (Y - X);
    total += grandes;
  }
  
  cout << total << endl;
  return 0;
}