#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 1; j < n; ++j)
    {
        for (int i = j; i < n; ++i)
        {
            int mn = INT_MAX;
            mn = min(mn, dp[i - j + 1][i] + v[i - j] * v[i - j + 1] * v[i + 1]);
            mn = min(mn, dp[i - j][i - 1] + v[i - j] * v[i] * v[i + 1]);

            for (int k = 0; k < j - 2; ++k)
            {
                mn = min(mn, dp[i - j][i - j + k + 1] + dp[i - j + k + 2][i] +
                                 v[i - j] * v[i - j + k + 2] * v[i + 1]);
            }

            dp[i - j][i] = mn;
        }
    }

    cout << dp[0][n - 1] << endl;
}