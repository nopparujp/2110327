#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> visited;
int n, e, k,connection;
void dfs(int i, int l) {
    // cout << i << " " << l << endl;
    visited[i] = 1;
    if (l < k) {
        for (auto t : v[i]) {
            if (!visited[t]) {
                connection++;
            }
            dfs(t, l + 1);
        }
    }
}

int main() {
    cin >> n >> e >> k;
    int a, b;
    v = vector<vector<int>>(n);
    while (e--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int max_connection = 0;
    for (int i = 0; i < n; ++i) {
        visited = vector<int>(n, 0);
        connection = 0;
        dfs(i, 0);
        // cout << i << ": " << tmp << endl;
        max_connection = max(connection, max_connection);
    }
    cout << max_connection + 1 << endl;
}