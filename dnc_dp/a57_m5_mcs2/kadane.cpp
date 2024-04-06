#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    int cur_max = v[0];
    int cur_min = v[0];
    int max_so_far = v[0];
    int min_so_far = v[0];

    for (int i = 1; i < n; ++i) {
        cur_max = max(cur_max + v[i], v[i]);
        max_so_far = max(max_so_far, cur_max);
        cur_min = min(cur_min + v[i], v[i]);
        min_so_far = min(min_so_far, cur_min);
    }

    if (sum == min_so_far)
        cout << max_so_far << endl;
    else
        cout << max(sum - min_so_far, max_so_far) << endl;
}
