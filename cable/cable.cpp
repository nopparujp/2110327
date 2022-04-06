#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k = n - 1;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int tmp;
            cin >> tmp;
            g[i][j + i + 1] = tmp;
            g[j + i + 1][i] = tmp;
        }
        --k;
    }
    vector<int> d(n, 1e9), mst(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    d[0] = 0;
    while (!pq.empty()) {
        auto [w, p] = pq.top();
        pq.pop();
        mst[p] = true;
        for (int i = 0; i < n; ++i) {
            if (!mst[i] && p != i && g[p][i] < d[i]) {
                d[i] = g[p][i];
                pq.push({d[i], i});
            }
        }
    }
    int mx = 0;
    for (auto i : g) {
        for (auto j : i) {
            mx = max(mx, j);
            cout << j << " ";
        }
        cout << "\n";
    }
    for(auto i : d){
        cout << i << " ";
    }
}