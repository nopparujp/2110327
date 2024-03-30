#include <bits/stdc++.h>
using namespace std;
int N, M, x;
int arr[100000];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> x;

        int l = 0, r = N - 1;
        if (x < arr[l])
            cout << -1 << endl;
        else if (x >= arr[r]) {
            cout << r << endl;
        } else {
            while (r - l != 1) {
                int m = (l + r) >> 1;
                if (arr[m] > x) {
                    r = m;
                } else
                    l = m;
            }
            cout << l << endl;
        }
    }
}

