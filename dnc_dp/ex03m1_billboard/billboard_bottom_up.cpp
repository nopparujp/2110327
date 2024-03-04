#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    cin >> v[1];
    for (int i = 2; i < n; ++i)
    {
        cin >> v[i];
        v[i] = max(v[i] + v[i - 2], v[i - 1]);
    }

    cout << v[n - 1];
}