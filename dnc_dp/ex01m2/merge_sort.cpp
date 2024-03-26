#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int start, int stop) {
    if (stop <= start)
        return 0;

    int inversions = 0;
    int m = (start + stop) >> 1;
    int i = 0, j = 0;
    int v1s = m - start + 1;
    int v2s = stop - m;
    int k = start;
    vector<int> v1;
    vector<int> v2;

    for (int idx = 0; idx < v1s; ++idx) {
        v1.push_back(v[start + idx]);
    }
    for (int idx = 0; idx < v2s; ++idx) {
        v2.push_back(v[m + 1 + idx]);
    }

    while (i < v1s && j < v2s) {
        if (v1[i] > v2[j]) {
            v[k++] = v1[i++];
            inversions += v2s - j;
        } else {
            v[k++] = v2[j++];
        }
    }

    while (i < v1s) {
        v[k++] = v1[i++];
    }
    while (j < v2s) {
        v[k++] = v2[j++];
    }

    return inversions;
}

int dnc(vector<int> &v, int start, int stop) {
    int inversions = 0;
    int m = (start + stop) >> 1;

    if (m > start) {
        inversions += dnc(v, start, m);
    }
    if (stop > m + 1) {
        inversions += dnc(v, m + 1, stop);
    }
    if (stop > start) {
        inversions += merge(v, start, stop);
    }

    return inversions;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << dnc(v, 0, n - 1) << endl;
}
