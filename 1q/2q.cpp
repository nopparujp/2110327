#include <bits/stdc++.h>
#include <functional>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int n, m, k, mn = 1e9;
vector<int> v;
void cal(int step, int m, int sum) {
    if (m == 0 && abs(sum - k) < mn) {
        mn = abs(sum - k);
        return;
    }
    if (step >= n)
        return;
    if (abs((v[step] + sum) - k) > mn) {
        cal(step + 1, m - 1, sum + v[step]);
    }
    cal(step + 1, m, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    v = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cal(0, m, 0);
    cout << mn;
    // for (auto i : v)
    //     cout << i;
}