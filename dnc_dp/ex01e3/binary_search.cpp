#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    int q, l, r;
    for (int i = 0; i < M; ++i) {
        cin >> q;
        l = 0;
        r = N - 1;

        if (v[0] > q) {
            cout << -1 << endl;
        } else if (v[N - 1] <= q) {
            cout << v[N - 1] << endl;
        } else {
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (q >= v[m]) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << v[l] << endl;
        }
    }
}
