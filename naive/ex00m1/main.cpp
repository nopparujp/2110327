#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int k = 0;
    int t = 0;

    while (k < m) {
        for (int &i : v) {
            if (k >= m) {
                return 0;
            }
            if (i == 0 || t % i == 0) {
                cout << t << endl;
                ++k;
            }
        }
        ++t;
    }
    return 0;
}
