#include <bits/stdc++.h>
using namespace std;

void findbridges(int node, vector<int> adj[], vector<int> &c, vector<int> &a, vector<int> &b, int t, vector<vector<int>> &bridges, int parent){
    c[node] = 1;
    a[node] = t;
    b[node] = t;
    t += 1;
    for(auto &it: adj[node]){
        if(it == parent){
            continue;
        }

        if(c[it] == 0) {
            findbridges(it, adj, c, a, b, t, bridges, node);
            b[node] = min(b[it], b[node]);

            if(b[it] > a[node]){
                bridges.push_back({it,node});
            }
        } else {
            b[node] = min(b[it], b[node]);
        }
    }
    
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> edges;
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        edges.push_back({u, v});
    }

    vector<int> a(N,0);
    vector<int> b(N,0);
    vector<int> c(N,0);
    vector<vector<int>> bridges;
    vector<int> adj[N];

    for (auto &it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for (int i = 0; i < N; i++) {
        if (c[i] == 0) {
            findbridges(i, adj, c, a, b, 1, bridges, -1);
        }
    }
    cout << max(0, (int) bridges.size() - K) << endl;
}