#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int len, n;
vector<bool> used;
vector<int> v, cons;
void permu(int idx) {

    if (idx == len) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < len; ++i) {
        if (!used[i]) {
            if (cons[i] != -1 && !used[cons[i]]) {
                continue;
            }
            used[i] = 1;
            v[idx] = i;
            permu(idx + 1);
            used[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> len >> n;
    used = vector<bool>(len);
    cons = vector<int>(len, -1);
    v = vector<int>(len);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        cons[b] = a;
    }
    permu(0);
}