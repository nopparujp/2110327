#include <bits/stdc++.h>
using namespace std;
vector<int> v(46, 0);
int fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (v[n] != 0)
        return v[n];
    v[n] = fibo(n - 1) + fibo(n - 2);
    return v[n];
}

int main() {
    int N;
    cin >> N;
    cout << fibo(N) << endl;
}
