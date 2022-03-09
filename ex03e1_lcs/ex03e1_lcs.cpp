#include <bits/stdc++.h>
using namespace std;

string a, b;
int solve(int row, int col, vector<vector<int>> &table) {
    if (row  < 0 || col < 0) {
        return 0;
    }

    if (table[row][col] != 0)
        return table[row][col];

    if (a[row] == b[col]) {
        table[row][col] = solve(row - 1, col - 1, table) + 1;
        return table[row][col];
    }
    table[row][col] =
        max(solve(row, col - 1, table), solve(row - 1, col, table));
    return table[row][col];
}

int main() {
    cin >> a >> b;

    vector<vector<int>> table(501, vector<int>(501, 0));
    cout << solve(a.length()-1,b.length()-1,table);
}