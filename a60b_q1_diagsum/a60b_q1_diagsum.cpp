#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<vector<int>> v;
    v = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }

    int mx = v[0][0],max_now = 0;
    for (int i = 0; i < n; ++i) {
        max_now = v[0][i];
        for (int j = 1; j < n - i; ++j) {
            max_now = max(v[j][i + j], v[j][i + j] + max_now);
            mx = max(mx, max_now);
        }
        max_now = v[i][0];
        for(int j = 1; j < n-i;++j){
            max_now = max(v[i+j][j],v[i+j][j]+max_now);
            mx = max(mx,max_now);
        }

    }
    cout << mx ;
    return 0;
}