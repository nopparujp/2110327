#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(31, vector<int>(31, -1));
int c(int n, int k) {
    if (n == k || k == 0)
        return 1;

    if (v[n][k] != -1)
        return v[n][k];

    v[n][k] = c(n - 1, k - 1) + c(n - 1, k);
    return v[n][k];
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << c(N, K) << endl;
}
