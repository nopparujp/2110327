#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
int n, ans = 0;
bool check_dia(vi table, int last) {
    for (int i = 0; i < last - 1; ++i) {
        for (int j = i + 1; j < last; ++j) {
            int cc = i, rc = table[i], co = j, ro = table[j];
            int dx = abs(cc - co), dy = abs(rc - ro);
            if (dx == dy)
                return false;
        }
    }
    return true;
}
void solve(vi table, int idx) {
    for (int i = 0; i < n; ++i) {
        bool f = false;
        for (int j = 0; j < idx; ++j) {
            if (table[j] == i) {
                f = true;
                break;
            }
        }
        if (!f) {
            table[idx] = i;
            if (check_dia(table, idx + 1))
                solve(table, idx + 1);
        }
    }
    if (idx == n)
        ++ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi table(n, -1);
    solve(table, 0);
    cout << ans;
}