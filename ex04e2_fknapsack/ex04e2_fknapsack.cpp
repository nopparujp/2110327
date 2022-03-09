#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
void print(vector<pair<double, double>> v) {
    for (auto i : v)
        cout << i.first << " " << i.second << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double mass;
    int n;
    cin >> mass >> n;

    vector<pair<double, double>> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }

    double spe;

    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
        if (v[i].second == 0){
            spe = v[i].first;
            v[i].first = 0;
        }
        else
            v[i].first /= v[i].second;
    }

    sort(v.begin(), v.end(), greater<pair<double, double>>());
    // sort(v.begin(), v.end(),
    //      [](pair<double, double> a, pair<double, double> b) {
    //          return a.first / a.second > b.first / b.second;
    //      });
    int k = 0;
    double value = 0;
    while (mass > 0 && k < v.size()) {
        if (mass - v[k].second <= 0) {
            value += mass * v[k].first;
            break;
            mass = 0;
        } else {
            value += v[k].first * v[k].second;
            mass -= v[k].second;
        }
        ++k;
    }
    value += spe;

    cout << fixed << setprecision(4) << value << "\n";
    return 0;
}
