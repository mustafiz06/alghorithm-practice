#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
void dfs(int a, int b) {
    if (a < 0 || a >= n || b < 0 || b >= m) return;
    if (grid[a][b] == '#') return;
    grid[a][b] = '#';
    dfs(a+1, b);
    dfs(a-1, b);
    dfs(a, b+1);
    dfs(a, b-1);
}
int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int apartments = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                apartments++;
            }
        }
    }

    cout << apartments << endl;
}