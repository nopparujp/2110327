#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x >> y;
    int table[n+1][m+1];
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m + 1; ++j) {
            cin >> table[i][j];
        }
    }

    int row = n, col = m;
    string ans;
    while (table[row][col] != 0) {
        if (table[row - 1][col - 1] < table[row][col]) {

            ans += x[min(row, col)];
        }
            --row;--col;

    }
    reverse(ans.begin(),ans.end());
    cout << ans;

}