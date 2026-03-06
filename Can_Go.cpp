#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool visited[1005][1005];
bool found = false;

void dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] == '#' || visited[r][c]) return;
    if (grid[r][c] == 'B') {
        found = true;
        return;
    }
    visited[r][c] = true;
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}
int main() {
    cin >> n >> m;
    int startR=0;
    int startC=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                startR = i;
                startC = j;
            }
        }
    }
    dfs(startR, startC);
    if (found) cout << "YES";
    else cout << "NO";

    return 0;
}