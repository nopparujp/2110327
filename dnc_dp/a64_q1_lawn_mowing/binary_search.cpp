#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, M, K;
vector<int> A;

int cal_grass(int l, int r) {
    if (l == 0)
        return A[r];
    return A[r] - A[l - 1];
}

int cal_price(int l, int r) { return cal_grass(l, r) + (r - l + 1) * K; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    A = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i < N; ++i) {
        A[i] += A[i - 1];
    }

    int start, budget, lb, ub, md;
    for (int i = 0; i < M; ++i) {
        cin >> start >> budget;

        int max_price = cal_price(start, N - 1);
        int min_price = cal_price(start, start);

        if (max_price <= budget) {
            cout << cal_grass(start, N - 1) << "\n";
        } else if (min_price > budget) {
            cout << 0 << "\n";
        } else {
            lb = 0;
            ub = N - 1;

            while (ub - lb > 1) {
                md = (lb + ub) >> 1;
                int p = cal_price(start, md);

                if (p <= budget)
                    lb = md;
                else
                    ub = md;
            }

            cout << cal_grass(start, lb) << "\n";
        }
    }
}
