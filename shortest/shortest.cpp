#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e, s;
    cin >> n >> e >> s;
    vector<iii> v(n);
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a, b, c);
    }
    vector<int> d(n, 1e9);
    d[s] = 0;
    for (int k = 1; k < n; ++k) {
        for (auto [i, j, w] : v) {
            if (d[i] + w < d[j]) {
                d[j] = d[i] + w;
            }
        }
    }
    for (auto [i, j, w] : v) {
        if (d[i] + +w < d[j]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (auto i : d) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}