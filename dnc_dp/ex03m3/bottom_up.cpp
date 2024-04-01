#include <bits/stdc++.h>
#include <climits>
using namespace std;

int N, K, p[10000];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    vector<int> table(N, INT_MAX);
    for (int i = 0; i <= min(N - 1, K); ++i) {
        table[i] = p[i];
    }

    for (int i = K + 1; i < N; ++i) {
        for (int j = i - 1; j >= max(0, i - 2 * K - 1); --j) {
            table[i] = min(p[i] + table[j], table[i]);
        }
    }

    int m = INT_MAX;
    for (int i = N - 1; i >= max(0, N - K - 1); --i) {
        m = min(m, table[i]);
    }

    cout << m << endl;
}
