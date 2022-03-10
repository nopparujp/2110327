#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, c, n;
    cin >> r >> c >> n;
    int p[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> p[i][j];
        }
    }
    for (int j = 1; j < c; ++j) {
        p[0][j] += p[0][j - 1];
    }
    for (int i = 1; i < r; ++i) {
        p[i][0] += p[i - 1][0];
        for (int j = 1; j < c; ++j) {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }

    // p(r2,c2) – P(r1-1,c2) – P(r2,c1-1) + P(r1-1,c1-1).
    for (int i = 0; i < n; ++i) {

        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sol1, sol2, sol3;
        if (r1 == 0)
            sol1 = 0;
        else
            sol1 = p[r1 - 1][c2];
        if (c1 == 0)
            sol2 = 0;
        else
            sol2 = p[r2][c1 - 1];
        if (c1 == 0 || r1 == 0)
            sol3 = 0;
        else
            sol3 = p[r1 - 1][c1 - 1];
        int result = p[r2][c2] - sol1 - sol2 + sol3;
        cout << result << "\n";
    }
}