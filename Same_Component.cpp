#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n &&
            ny >= 0 && ny < m &&
            !visited[nx][ny] &&
            grid[nx][ny] == '.') {

            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (grid[x1][y1] == '-' || grid[x2][y2] == '-') {
        cout << "NO";
        return 0;
    }

    dfs(x1, y1);

    if (visited[x2][y2])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}