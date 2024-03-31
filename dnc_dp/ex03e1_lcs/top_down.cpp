#include <iostream>
using namespace std;

string a, b;
int table[500][500];

int solve(int ia, int ib) {
    if (ia < 0 || ib < 0) {
        return 0;
    }

    if (table[ia][ib] != 0)
        return table[ia][ib];

    if (a[ia] == b[ib]) {
        table[ia][ib] = solve(ia - 1, ib - 1) + 1;
        return table[ia][ib];
    }

    table[ia][ib] = max(solve(ia, ib - 1), solve(ia - 1, ib));
    return table[ia][ib];
}

int main() {
    cin >> a >> b;
    cout << solve(a.length() - 1, b.length() - 1) << endl;
}
