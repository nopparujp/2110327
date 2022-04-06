#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp, a, b;
    cin >> n >> m >> k;
    vector<int> w(n);
    vector<vector<int>> g(n);
    vector<int> init;
    vector<int> d(n, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < k; ++i) {
        cin >> a;
        init.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (auto i : init) {
        pq.push({w[i], i});
        d[i] = w[i];
    }
    while (!pq.empty()) {
        auto [wei, i] = pq.top();
        pq.pop();
        if (wei != d[i])
            continue;
        for (auto k : g[i]) {
            if (d[k] > w[k] + wei) {
                d[k] = w[k] + wei;
                pq.push({d[k], k});
            }
        }
    }
    int mx = 0;
    for (auto i : d) {
        mx = max(i, mx);
    }
    cout << mx << endl;
}