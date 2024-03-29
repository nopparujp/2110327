#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod(int n,int k) {

    if (n == 1)
        return 2;
    int j = n/2;
    if (n % 2 != 0) {
        return (mod(j,k) * mod(j,k) * 2) % k;
    } else
        return (mod(j,k) * mod(j,k)) % k;
}
int main() {
    int n,k;
    cin >> n >> k;
    cout << mod(n,k);
}