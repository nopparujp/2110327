#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, R;
    cin >> r >> c >> R;
    int a[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }

    int r1, c1, r2, c2, m;
    for (int k = 0; k < R; ++k) {
        cin >> r1 >> c1 >> r2 >> c2;

        --r1;
        --r2;
        --c1;
        --c2;

        if (r1 > r2 || c1 > c2) {
            cout << "INVALID" << endl;
        }

        else if (r1 >= r || c1 >= c) {
            cout << "OUTSIDE" << endl;
        }

        else {
            m = a[r1][c1];
            for (int i = r1; i <= min(r2, r - 1); ++i) {
                for (int j = c1; j <= min(c2, c - 1); ++j) {
                    m = max(m, a[i][j]);
                }
            }
            cout << m << endl;
        }
    }
}
