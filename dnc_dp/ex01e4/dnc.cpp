#include <bits/stdc++.h>
using namespace std;

int dnc(int base, unsigned int exponent, int modulus) {
    int result = 1;

    if (exponent == 1) {
        return base;
    }
    if (exponent == 0) {
        return 1;
    }

    result = dnc(base, exponent / 2, modulus);
    result *= result;
    result %= modulus;
    if (exponent % 2 != 0) {
        result *= base;
        result %= modulus;
    }

    return result;
}

int main() {
    unsigned int X, N, K;
    cin >> X >> N >> K;
    cout << dnc(X % K, N, K) << endl;
}
