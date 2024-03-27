#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> Q;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), Q + 1) - 1;
        if (*it == 0)
            cout << -1 << endl;
        else
            cout << *it << endl;
    }
}
