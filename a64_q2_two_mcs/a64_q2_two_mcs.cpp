
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<vector<int>> v) {
    for (auto i : v) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, max1, max2 = 0;
    pair<int, int> p = {0, 0};
    cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    vector<int> qs(n);

    cin >> qs[0];
    table[0][0] = qs[0];
    max1 = table[0][0];
    for (int i = 1; i < n; ++i) {
        cin >> table[i][i];
        qs[i] = qs[i - 1] + table[i][i];
        table[0][i] = qs[i];
        if (max1 < table[i][i]) {
            max1 = table[i][i];
            p = {i, i};
        }
        if(max1<qs[i]){
            max1 = qs[i];
            p = {0,i};
        }
    }
    

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            table[i][j] = qs[j] - qs[i - 1];
            if (max1 < table[i][j]) {
                max1 = table[i][j];
                p = {i, j};
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (max2 <= table[i][j] && (j < p.first - 1 || i > p.second + 1)) {
                max2 = table[i][j];
            }
        }
    }
    // print(table);
    // cout << endl;
    // cout << "max1 " << max1 << endl;
    // cout << "max2 " << max2 << endl;
    cout << max1 + max2;
}