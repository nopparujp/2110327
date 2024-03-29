#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
vector<vector<int>> g, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    g = vector<vector<int>>(r, vector<int>(c));
    d = vector<vector<int>>(r, vector<int>(c, 1e9));
    d[0][0] = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> g[i][j];
        }
    }
    vector<pair<int, int>> direction{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    priority_queue<piii, vector<piii>, greater<piii>> h;
    h.emplace(0, make_pair(0, 0));
    while (!h.empty()) {
        auto [w, u] = h.top();
        auto [x, y] = u;
        h.pop();

        for (auto [dx, dy] : direction) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            else {
                if (w + g[nx][ny] < d[nx][ny]) {
                    h.emplace(d[nx][ny] = w + g[nx][ny], make_pair(nx, ny));
                }
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}