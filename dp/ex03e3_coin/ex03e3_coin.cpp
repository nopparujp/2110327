#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n_coin, cash, coin;
    vector<int> vc;
    cin >> n_coin >> cash;
    vector<int> dp(cash + 1, cash + 1);
    dp[0] = -1;
    for (int i = 0; i < n_coin; ++i)
    {
        cin >> coin;
        vc.push_back(coin);
    }
    for (int i = 1; i < cash + 1; ++i)
    {
        // check coin
        bool is_one = false;
        for (int j = 0; j < n_coin; ++j)
        {
            if (vc[j] == i)
            {
                dp[i] = 1;
                is_one = true;
            }
        }

        // find coin in vc
        if (!is_one)
        {
            for (int k = 1; k < i; ++k)
            {
                for (int j = 0; j < n_coin; ++j)
                {
                    if (dp[k] != -1 && k + vc[j] == i && dp[k] + 1 < dp[i])
                    {
                        dp[i] = dp[k] + 1;
                    }
                }
            }
        }
    }
    if (dp[cash] > cash)
    {
        cout << -1 << endl;
    } else
        cout << dp[cash] << endl;
}
