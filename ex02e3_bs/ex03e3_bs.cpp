#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &v, int &query) {
    int begin = 0;
    int end = v.size()-1;
    int mid;
    if (query < v[0])
        return -1;
    if (query >= v[end])
        return end;
    while (end - begin  != 1) {
    mid = (begin + end) >> 1;
        // cout << end - begin << endl;
        // cout << "end "  <<  end << endl;
        // cout <<"begin " << begin << endl;
        // cout <<"mid" << mid << endl;
        if (v[mid] > query) {
            end = mid;
        } else {
            begin = mid;
        }
    }
        return begin;
}
int main() {
    int n, m, query;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> query;
        cout << search(v,query) << "\n";
    }
}