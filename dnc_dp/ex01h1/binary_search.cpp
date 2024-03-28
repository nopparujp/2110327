#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int findPosition(vector<int> &v, int x) {
    auto it = lower_bound(v.begin(), v.end(), x);
    return it - v.begin();
}

int main() {
    int M = 2e9;
    int k = 1;
    vector<int> v(1, 0);
    while (v[k - 1] < M) {
        v.push_back(v[k - 1] + findPosition(v, k));
        k++;
    }

    int N, X;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X;
        cout << findPosition(v, X) << endl;
    }
}
