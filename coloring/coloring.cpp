#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
#define vi vector<int>
int n, e;
vector<vi> g;
vi color;
bool paint(int mx, int step) {
    if (step == n)
        return true;
    for (int i = 0; i < mx; i++) {
        bool canpaint = true;
        for (auto j : g[step]) {
            if (color[j] == i) {
                // cant paint
                canpaint = false;
                break;
            }
        }
        if (canpaint) {
            color[step] = i;
            if (paint(mx, step + 1))
                return true;
            color[step] = -1;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    g = vector<vi>(n);
    color = vector<int>(n, -1);
    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i < n; ++i) {
        if (paint(i, 0)){

            cout << i << endl;
            return 0;
        }
    }
    cout << n <<  endl;
    return 0;
}