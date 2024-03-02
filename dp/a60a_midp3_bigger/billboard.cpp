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
        int a = max(v[i], v[i - 1]);
        v[i] = max(v[i] + v[i - 3], a);
    }
    cout << v[n - 1];
}