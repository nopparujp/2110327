#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, t;
    cin >> h >> m >> t;
    h = (((m + t) / 60) + h) % 24;
    m = (m + t) % 60;
    if (h < 10)
        cout << 0;
    cout << h << ' ';
    if (m < 10)
        cout << 0;
    cout << m << endl;
}
