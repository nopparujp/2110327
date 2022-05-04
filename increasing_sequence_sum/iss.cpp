#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int n, ans = 0;
void cal(int s, int l) {
    for (int i = l; i < n; ++i) {
        if (s + i <= n)
            cal(s + i, i);
        else
            break;
    }
    if (s == n)
        ++ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cal(0,1);
    cout << ans;
}