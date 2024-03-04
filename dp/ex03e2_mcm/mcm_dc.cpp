#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &v, int l, int r)
{
    // (0)(1-4)
    // (0-1)(2-4)
    // ...
    // (0-3)(4)
    if (l == r)
        return 0;

    int mn = INT_MAX;
    for (int i = l; i < r; ++i)
    {

        mn = min(mcm(v, l, i) + mcm(v, i + 1, r) + v[l] * v[i + 1] * v[r + 1],
                 mn);
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> v[i];
    }
    cout << mcm(v, 0, n - 1);
}