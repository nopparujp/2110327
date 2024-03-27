#include <iostream>
using namespace std;

int modPow(int base, unsigned int exponent, int modulus) {
    if (modulus == 1)
        return 0;

    base = base % modulus;
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    unsigned int X, N, K;
    cin >> X >> N >> K;

    cout << modPow(X, N, K) << endl;
}
