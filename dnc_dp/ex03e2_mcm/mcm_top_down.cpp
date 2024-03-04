
#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &v, int l, int r, vector<vector<int>> &table)
{
    // (0)(1-4)
    // (0-1)(2-4)
    // ...
    // (0-3)(4)
    if (l == r)
        return 0;

    if (table[l][r] != INT_MAX)
    {
        return table[l][r];
    }

    for (int i = l; i < r; ++i)
    {

        table[l][r] = min(mcm(v, l, i, table) + mcm(v, i + 1, r, table) +
                              v[l] * v[i + 1] * v[r + 1],
                          table[l][r]);
    }
    return table[l][r];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> table(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> v[i];
    }
    cout << mcm(v, 0, n - 1, table);
}