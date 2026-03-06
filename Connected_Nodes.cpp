#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        if(adj[x].empty()) {
            cout << -1;
        } else {
            sort(adj[x].rbegin(), adj[x].rend());
            for(int node : adj[x]) {
                cout << node << " ";
            }
        }
        cout << endl;
    }

    return 0;
}