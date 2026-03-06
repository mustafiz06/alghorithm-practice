#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[1005][1005];
bool shown[1005][1005];

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 0;
    if (grid[r][c] == '#' || shown[r][c]) return 0;
    shown[r][c] = true;
    int count = 1;
    count += dfs(r+1, c);
    count += dfs(r-1, c);
    count += dfs(r, c+1);
    count += dfs(r, c-1);

    return count;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> apartments;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !shown[i][j]) {
                int size = dfs(i, j);
                apartments.push_back(size);
            }
        }
    }
    if (apartments.empty()) {
        cout << 0;
        return 0;
    }
    sort(apartments.begin(), apartments.end());
    for (int x : apartments) {
        cout << x << " ";
    }



    return 0;
}