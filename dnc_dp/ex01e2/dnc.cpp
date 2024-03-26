#include <bits/stdc++.h>
using namespace std;

int get_sum(vector<int> &acc_sum, int l, int r) {
    if (l == 0) {
        return acc_sum[r];
    }
    return acc_sum[r] - acc_sum[l - 1];
}

int dnc(vector<int> &v, vector<int> &acc_sum, int start, int stop) {
    if (start == stop) {
        return v[start];
    }

    int m = (start + stop) / 2;

    int max_left = dnc(v, acc_sum, start, m);
    int max_right = dnc(v, acc_sum, m + 1, stop);

    int max_mid_left = get_sum(acc_sum, m, m);
    int max_mid_right = get_sum(acc_sum, m + 1, m + 1);

    for (int i = start; i < m; ++i) {
        max_mid_left = max(max_mid_left, get_sum(acc_sum, i, m));
    }

    for (int j = m + 2; j <= stop; ++j) {
        max_mid_right = max(max_mid_right, get_sum(acc_sum, m + 1, j));
    }

    int max_mid = max_mid_left + max_mid_right;

    return max(max_mid, max(max_left, max_right));
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n), acc_sum(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // accumualate sum
    acc_sum[0] = v[0];
    for (int i = 1; i < n; ++i) {
        acc_sum[i] = acc_sum[i - 1] + v[i];
    }

    cout << dnc(v, acc_sum, 0, n - 1) << endl;
}
