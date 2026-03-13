#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool pileOfWord(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    vector<int> count(26, 0);
    for (char c : s1)
    {
        count[c - 'a']++;
    }
    for (char c : s2)
    {
        count[c - 'a']--;
    }
    for (int x : count)
        if (x != 0)
        {
            return false;
        }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (pileOfWord(s1, s2) ? "YES" : "NO") << endl;
    }
    return 0;
}