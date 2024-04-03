#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define cvvll const vvll
using namespace std;
const ll MOD = 1e8 + 7;

vvll mul(cvvll &l, cvvll &r) {
    vvll res = vvll(4, vll(4, 0));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                res[i][j] = (res[i][j] + ((l[i][k] * r[k][j]) % MOD)) % MOD;
    return res;
}

vvll pow(cvvll &matrix, ll n) {
    if (n == 1) {
        return matrix;
    }

    vvll half_pow = pow(matrix, n / 2);
    vvll res = mul(half_pow, half_pow);

    if (n % 2 != 0)
        res = mul(res, matrix);
    return res;
}

int main() {
    ll N, sum = 0;
    cin >> N;

    vvll matrix = {{1, 0, 1, 0}, {1, 0, 0, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}};
    vvll res = pow(matrix, N - 2);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sum = (sum + res[i][j]) % MOD;
        }
    }

    cout << sum << endl;
}
