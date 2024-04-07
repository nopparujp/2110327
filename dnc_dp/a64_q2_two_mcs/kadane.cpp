#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int cur_sum1 = v[0], max_so_far1 = v[0];
    int cur_sum2 = v[0], max_so_far2 = v[0];

    for (int i = 1; i < n; ++i) {
        cur_sum2 = max(cur_sum2 + v[i], max_so_far1 + v[i]);
        max_so_far2 = max(max_so_far2, cur_sum2);

        cur_sum1 = max(v[i], v[i] + cur_sum1);
        max_so_far1 = max(max_so_far1, cur_sum1);
    }
    cout << max(max_so_far1, max_so_far2) << endl;
}
