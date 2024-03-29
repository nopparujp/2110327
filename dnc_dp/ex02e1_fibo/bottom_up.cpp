#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int fi = 0, fn = 1, tmp = 0;
    for (int i = 0; i < N; ++i) {
        tmp = fn;
        fn = fi + fn;
        fi = tmp;
    }
    cout << fi << endl;
}
