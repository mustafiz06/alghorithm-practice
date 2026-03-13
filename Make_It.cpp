#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

bool canReach(int n)
{
    if (n == 1)
    {
        return true;
    }

    queue<int> q;
    unordered_set<int> visited;

    q.push(1);
    visited.insert(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == n)
        {
            return true;
        }

        int addOp = curr + 4;
        int mulOp = curr * 2;

        if (addOp <= n && visited.find(addOp) == visited.end())
        {
            visited.insert(addOp);
            q.push(addOp);
        }

        if (mulOp <= n && visited.find(mulOp) == visited.end())
        {
            visited.insert(mulOp);
            q.push(mulOp);
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (canReach(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}