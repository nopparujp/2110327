#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool check(vector<int> &d, vector<int> v) {
    for (auto i : v) {
        if (d[i] == false)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e, a, b;
    cin >> n >> e;
    vector<vector<int>> g(n + 1);
    vector<int> d(n + 1);
    while (e--) {
        cin >> a >> b;
        g[b].push_back(a);
    }
    for (int i = 0; i < 5; ++i) {
        d = vector<int>(n + 1, false);
        bool c = true;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (check(d, g[a])) {
                d[a] = true;
            } else {
                c = false;
            }
        }
        cout << (c ? "SUCCESS\n" : "FAIL\n");
    }
}