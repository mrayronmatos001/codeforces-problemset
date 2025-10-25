#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N;
  cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    g[A].push_back(B);
    g[B].push_back(A);
  }
  auto calc_dist = [&](int root) {
    vector<int> dist(N, -1);
    queue<int> Q;
    Q.push(root), dist[root] = 0;
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      for (int d : g[c]) {
        if (dist[d] != -1) continue;
        Q.push(d), dist[d] = dist[c] + 1;
      }
    }
    return dist;
  };
  auto d0 = calc_dist(0);
  int u = N - 1;
  for (int i = N - 2; i >= 0; i--) {
    if (d0[i] > d0[u]) u = i;
  }
  auto du = calc_dist(u);
  int v = N - 1;
  for (int i = N - 2; i >= 0; i--) {
    if (du[i] > du[v]) v = i;
  }
  auto dv = calc_dist(v);
  for (int i = 0; i < N; i++) {
    if (du[i] > dv[i]) {
      cout << u + 1 << "\n";
    } else if (du[i] == dv[i]) {
      cout << max(u, v) + 1 << "\n";
    } else {
      cout << v + 1 << "\n";
    }
  }
}