#include <bits/stdc++.h>
using namespace std;
int con = (int)1e8 + 7;
void cal(vector<int> &v, int t) {
    for (int i = 3; i <= t; ++i) {
        vector<int> tmp = v;
        v[0] = (tmp[0] + tmp[2]) % con;
        v[1] = tmp[0];
        v[2] = (tmp[1] + tmp[3]) % con;
        v[3] = (tmp[3] + tmp[1]) % con;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> v(4, 1);
    cal(v,n);
    for (auto &i : v) {
        sum += i;
        sum %= con;
    }
    cout << sum << endl;
    return 0;
}