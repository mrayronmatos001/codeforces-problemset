#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;

    vector<pair<int,int>> edges(M);

    for (int i=0; i<M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int minConflicts = M;

    for (int mask=0; mask < (1 << N); mask++) {
        vector<int> colors(N+1);
        for (int v=1;v<=N;v++) {
            colors[v]= (mask >> (v-1)) & 1;
        }

        int conflicts=0;
        for (int i=0; i<M;i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            if(colors[u]==colors[v]) {
                conflicts++;
            }
        }

        minConflicts = min(minConflicts,conflicts);
    }

    cout << minConflicts << endl;
}