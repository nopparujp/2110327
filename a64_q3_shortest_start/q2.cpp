#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <tuple>
#include <utility>
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
    vector<iii> g;
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
        g.push_back(make_tuple(a, b, w));
    }
    vector<int> d(n, 1e9);
    int shortest = INT_MAX;
    for (auto &s : start) {
        fill(d.begin(), d.end(), 1e9);
        bool change = false;
        d[s] = 0;
        for (int j = 1; j < n; ++j) {
            change = false;
            for (auto &[x, y, wei] : g) {
                if (d[x] + wei < d[y]) {
                    change = true;
                    d[y] = d[x] + wei;
                }
            }
            if (!change)
                break;
        }
        shortest = min(shortest, d[goal]);
    }
    cout << shortest << "\n";
    return 0;
}