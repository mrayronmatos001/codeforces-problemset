#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W;
    cin >> H >> W;
    
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }
    
    // Encontrar posição de Takahashi e todo o lixo
    int tx = -1, ty = -1;
    set<pair<int, int>> initial_trash;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            } else if (grid[i][j] == '#') {
                initial_trash.insert({i, j});
            }
        }
    }
    
    // BFS no espaço de estados
    map<set<pair<int, int>>, int> dist;
    queue<set<pair<int, int>>> q;
    
    q.push(initial_trash);
    dist[initial_trash] = 0;
    
    // Direções: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while (!q.empty()) {
        set<pair<int, int>> current = q.front();
        q.pop();
        
        // Estado objetivo: nenhum lixo
        if (current.empty()) {
            cout << dist[current] << "\n";
            return 0;
        }
        
        // Tentar cada uma das 4 direções
        for (int dir = 0; dir < 4; dir++) {
            set<pair<int, int>> next_state;
            bool gets_dirty = false;
            
            // Mover todo o lixo simultaneamente
            for (auto [x, y] : current) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                // Se lixo sai do grid, desaparece
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    continue;
                }
                
                // Se lixo vai para onde Takahashi está, fica sujo
                if (nx == tx && ny == ty) {
                    gets_dirty = true;
                    break;
                }
                
                next_state.insert({nx, ny});
            }
            
            // Se ficou sujo, esse movimento não é válido
            if (gets_dirty) {
                continue;
            }
            
            // Se é um estado novo, adicionar à fila
            if (dist.find(next_state) == dist.end()) {
                dist[next_state] = dist[current] + 1;
                q.push(next_state);
            }
        }
    }
    
    // Se chegou aqui, é impossível
    cout << -1 << "\n";
    
    return 0;
}