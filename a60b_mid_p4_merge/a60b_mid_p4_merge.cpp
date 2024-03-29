#include <bits/stdc++.h>
using namespace std;
#define ll long long
int value;
void fill(int l, int r, int k, int *arr) {
    if (((r - l) << 1) - 1 == k) {
        for (int i = l; i < r; ++i) {
            arr[i] = value--;
        }

    } else if (k == 1) {
        int tmp = value + 1;
        for (int i = r - 1; i >= l; --i) {
            arr[i] = value--;
        }

    } else {
        int m = (l + r) >> 1;
        // int max_k = ((r - l) >> 1) + 1;
        int max_k = ((r - l) / 2);
        max_k*=2;
        max_k--;
        fill(l, m, min(max_k, k - 2), arr);
        fill(m, r, k - min(max_k, k - 2) - 1, arr);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    value = n;
    int arr[n];
    if (m > 2 * n - 1 || m % 2 == 0)
        cout << -1 << "\n";
    else {
        fill(0, n, m, arr);
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
}