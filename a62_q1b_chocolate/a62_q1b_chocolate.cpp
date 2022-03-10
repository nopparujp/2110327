#include <bits/stdc++.h>
using namespace std;

int n, m, c = 1e6 + 3;
vector<int> v, table;

int cal() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[j] <= i) {
                table[i] += table[i - v[j]];
                table[i] %= c;
            }
        }
    }
    return table[n];
}

int main() {
    cin >> n >> m;
    v = vector<int>(m);
    table = vector<int>(n+1);

    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    table[0] = 1;
    cout << cal();
    return 0;
}