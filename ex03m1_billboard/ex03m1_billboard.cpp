#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> table;
int cal(vector<int> &v, int stop) {
    if (stop == 0)
        return v[0];
    if (stop < 0)
        return 0;
    if (table[stop] != 0)
        return table[stop];
    table[stop] = max(cal(v, stop - 2) + v[stop], cal(v, stop - 1));

    return table[stop];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    table.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << cal(v, v.size() - 1);
}