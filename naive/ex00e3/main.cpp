#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, tmp;
    cin >> n;
    set<int> s;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp < 1 || tmp > n) {
            cout << "NO" << endl;
            return 0;
        }
        s.insert(tmp);
    }

    cout << (s.size() == n ? "YES" : "NO") << endl;
    return 0;
}
