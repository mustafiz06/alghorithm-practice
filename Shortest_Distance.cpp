#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    const long long INF = 1e18;
    vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));

    for(int i=1;i<=n;i++)
        dist[i][i] = 0;

    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (long long)w);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int q;
    cin >> q;

    while(q--){
        int s,d;
        cin >> s >> d;

        if(dist[s][d] == INF) cout << -1 << endl;
        else cout << dist[s][d] << endl;
    }
}