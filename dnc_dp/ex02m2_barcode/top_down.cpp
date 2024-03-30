#include <bits/stdc++.h>
using namespace std;
int N, M, K, arr[2][31][31][31];

int solve(int c, int n, int m, int k) {
    if (m > M || k > K || N - n < K - k) {
        return 0;
    }

    if (n == N - 1) {
        return k == K;
    }

    if (arr[c][n][m][k] != 0) {
        return arr[c][n][m][k];
    }

    int a;
    if (c) {
        a = solve(0, n + 1, 1, k + 1) + solve(1, n + 1, m + 1, k);
        arr[c][n][m][k] = a;
    } else {
        a = solve(1, n + 1, 1, k + 1) + solve(0, n + 1, m + 1, k);
        arr[c][n][m][k] = a;
    }

    return a;
}

int main() {
    cin >> N >> M >> K;
    cout << solve(0, 0, 1, 0) << endl;
};
