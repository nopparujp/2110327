#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod(int x, int n, int k) {
    if (n == 1)
        return x % k;
    if (n % 2 == 0) {
        return (int)pow(mod(x, n / 2, k), 2) % k;
    }
    else 
    return ((int)pow(mod(x, n / 2, k), 2) % k * x) % k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, n, k;
    cin >> x >> n >> k;
    cout << mod(x, n, k) << endl;
}