#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v = vector<int>(N);
    vector<vector<int>> table(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    vector<int> s(v);
    sort(s.begin(), s.end());

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i] == s[j])
                table[i][j] = table[max(0, i - 1)][max(0, j - 1)] + 1;
            else
                table[i][j] =
                    max(table[i][max(0, j - 1)], table[max(0, i - 1)][j]);
        }
    }
    cout << table[N - 1][N - 1] << endl;
}
