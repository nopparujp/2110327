#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
vector<int> p;
int findset(int in) {
    while (in != p[in]) {
        in = p[in];
    }
    return in;
}
void unionset(int u, int v) {
    u = findset(u);
    v = findset(v);
    p[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    int tmp;
    p = vector<int>(n);
    p[n - 1] = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        p[i] = i;
        for (int j = i + 1; j < n; ++j) {
            cin >> tmp;
            pq.push({tmp, i, j});
        }
    }
    int sm = 0;
    while (!pq.empty()) {
        auto [w, i, j] = pq.top();
        pq.pop();
        if (findset(i) != findset(j)) {
            unionset(i, j);
            sm += w;
        }
    }
    cout << sm << "\n";
}