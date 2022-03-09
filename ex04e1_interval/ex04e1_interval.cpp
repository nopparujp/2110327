#include <bits/stdc++.h>
#include <random>
using namespace std;
int main() {
    int N, start, finish,c;
    cin >> N;
    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].second;
    }
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first;
    }
    sort(v.begin(),v.end());
    finish = v[0].first;
    c = 1;
    for (int i = 1; i < N; ++i) {
        if(v[i].second >= finish) {
            finish = v[i].first;
            ++c;
        }
    }
    cout << c;
}