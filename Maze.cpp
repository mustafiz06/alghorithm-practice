#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> rows >> cols;

    vector<string> maze(rows);
    int firstRow = -1, firstCol = -1;
    int lastRow = -1, lastCol = -1;

    for (int i = 0; i < rows; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'R')
            {
                firstRow = i;
                firstCol = j;
            }
            else if (maze[i][j] == 'D')
            {
                lastRow = i;
                lastCol = j;
            }
        }
    }

    int dr[] = {0, 0, -1, 1};
    int dc[] = {1, -1, 0, 0};

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    queue<pair<int, int>> q;
    q.push({firstRow, firstCol});
    visited[firstRow][firstCol] = true;

    bool foundPath = false;

    while (!q.empty())
    {
        auto [currentRow, currentCol] = q.front();
        q.pop();

        if (currentRow == lastRow && currentCol == lastCol)
        {
            foundPath = true;
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int newRow = currentRow + dr[dir];
            int newCol = currentCol + dc[dir];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                !visited[newRow][newCol] &&
                maze[newRow][newCol] != '#')
            {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = {currentRow, currentCol};
                q.push({newRow, newCol});
            }
        }
    }

    if (foundPath)
    {
        int currentRow = lastRow;
        int currentCol = lastCol;

        while (currentRow != firstRow || currentCol != firstCol)
        {
            if (maze[currentRow][currentCol] != 'R' && maze[currentRow][currentCol] != 'D')
            {
                maze[currentRow][currentCol] = 'X';
            }

            auto [prevRow, prevCol] = parent[currentRow][currentCol];
            currentRow = prevRow;
            currentCol = prevCol;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        cout << maze[i] << "\n";
    }

    return 0;
}