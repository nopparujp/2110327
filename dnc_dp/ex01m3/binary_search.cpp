#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    ll C;
    for (int i = 0; i < A; ++i) {

        cin >> C;
        if (C <= N) {
            cout << 0 << endl;
        } else {
            C -= N;
            ll max_time = T[0] * C;
            ll min_time = 0;

            while (max_time > min_time) {
                ll customer = 0;
                ll mid_time = (max_time + min_time) >> 1;

                for (auto &t : T) {
                    customer += mid_time / t;
                }

                if (customer < C) {
                    min_time = mid_time + 1;
                } else {
                    max_time = mid_time;
                }
            }

            cout << max_time << endl;
        }
    }

    return 0;
}
