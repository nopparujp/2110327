#include <bits/stdc++.h>
using namespace std;

// 00 - 0,1
// 01 - 0,1
// 10 - 0
// 11 - 0,1
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int MOD = (int)1e8 + 7;
    int N, a, b, sum = 0;
    vector<int> v(4, 1);
    cin >> N;

    for (int i = 3; i <= N; ++i) {
        a = (v[0] + v[2]) % MOD;
        b = (v[1] + v[3]) % MOD;

        v[1] = v[0];
        v[0] = a;
        v[2] = b;
        v[3] = b;
    }

    for (const auto &i : v) {
        sum = (sum + i) % MOD;
    }

    cout << sum << endl;
    return 0;
}
