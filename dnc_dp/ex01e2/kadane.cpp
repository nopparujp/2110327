#include <bits/stdc++.h>
using namespace std;

// 15
// 1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    int max_sum = v[0];
    int cur_sum = v[0];
    for (int i = 1; i < n; ++i)
    {
        cur_sum = max(cur_sum + v[i], v[i]);
        max_sum = max(max_sum, cur_sum);
    }
    cout << max_sum;
}
