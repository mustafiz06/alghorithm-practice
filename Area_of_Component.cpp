#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;

    if (visited[x][y] || grid[x][y] == '-')
        return 0;

    visited[x][y] = true;
    return 1 
        + dfs(x+1, y)
        + dfs(x-1, y)
        + dfs(x, y+1)
        + dfs(x, y-1);
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int minArea = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = dfs(i, j);
                minArea = min(minArea, area);
                found = true;
            }
        }
    }

    if (!found)
        cout << -1;
    else
        cout << minArea;

    return 0;
}