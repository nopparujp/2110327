
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> graph(n);
    cout << endl;
    int goal;
    cin >> goal;
    vector<int> start;
    int tmp;
    for (int i = 0; i < k; ++i) {
        cin >> tmp;
        start.push_back(tmp);
    }
    int a, b, w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    int shortest = INT_MAX;
    for (auto &s : start) {
        vector<int> d(n, 1e9);
        d[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            auto &[dis, cur] = pq.top();
            pq.pop();
            if (d[cur] != dis)
                continue;
            for (auto &[ncur, wei] : graph[cur]) {
                if (d[ncur] > dis + wei) {
                    d[ncur] = dis + wei;
                    pq.push({d[ncur], ncur});
                }
            }
        }
        shortest = min(shortest, d[goal]);
    }
    cout << shortest << "\n";
    return 0;
}