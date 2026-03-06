#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<tuple<int,int,int>> edges;

    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }

    int s;
    cin >> s;

    vector<long long> dist(n+1, 1e18);
    dist[s] = 0;

    for(int i=1;i<=n-1;i++){
        for(auto [u,v,w] : edges){
            if(dist[u] != 1e18 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(auto [u,v,w] : edges){
        if(dist[u] != 1e18 && dist[u] + w < dist[v]){
            cout << "Negative cycle detected";
            return 0;
        }
    }

    int t;
    cin >> t;

    while(t--){
        int d;
        cin >> d;

        if(dist[d] == 1e18) cout << "Not Possible\n";
        else cout << dist[d] << "\n";
    }
}