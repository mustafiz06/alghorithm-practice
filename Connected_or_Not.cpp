#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool adj[1005][1005] = {false};
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;

        if(a == b) {
            cout << "YES\n";
        }
        else if(adj[a][b]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}