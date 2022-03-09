#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool cal(ll &cust, ll &time, vector<int> &chef) {
    ll maxcust = 0;
    for (auto &x : chef) {
        maxcust += time / x;
    }
    if (maxcust >= cust) return true;
    else return false;
}
int main() {
    ll N, A, cust, left, right, mid;
    cin >> N >> A;
    vector<int> chef(N);
    for (int i = 0; i < N; ++i) {
        cin >> chef[i];
    }

    std::sort(chef.begin(), chef.end());
    for (int i = 0; i < A; ++i) {
        cin >> cust;
        if (cust < N)
            cout << "0\n";
        else {
        cust -= N;
        left = 0;
        right = chef[0] * cust;
            while (left < right) {
                mid = (left + right) >> 1;
                if (cal(cust, mid, chef))
                    right = mid;
                else
                    left = mid + 1;
            }
            cout << right << "\n";
        }
    }
}