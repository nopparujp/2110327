#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tri(100, vector<int>(100, -1));
vector<vector<int>> dp(100, vector<int>(100, -1));
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];
    int max_sum = dp[0][0];
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            int tl = 0, tr = 0, m = 0;
            tl = dp[i - 1][j] + tri[i][j];
            if (j >= 0)
                tr = dp[i - 1][j - 1] + tri[i][j];
            m = max(tl, tr);
            dp[i][j] = m;
            max_sum = max(max_sum, m);
        }
    }

    cout << max_sum << endl;
}
