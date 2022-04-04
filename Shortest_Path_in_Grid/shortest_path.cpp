#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, r;
    char tmp;
    vector<int> d1 = {0, 0, 1, -1};
    vector<int> d2 = {1, -1, 0, 0};
    cin >> c >> r;
    vector<vector<int>> distance(c + 2, vector<int>(r + 2, 0));
    vector<vector<int>> visited(c + 2, vector<int>(r + 2, 0));
    vector<vector<int>> map(c + 2, vector<int>(r + 2, 0));
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= r; ++j) {
            cin >> tmp;
            if (tmp == '#') {
                map[i][j] = 0;
            } else
                map[i][j] = 1;
        }
    }
    int i, j, ni, nj;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = 1;
        if (i == c && j == r) {
            cout << distance[i][j] << endl;
            return 0;
        }
        for (int k = 0; k < 4; ++k) {
            ni = i + d1[k];
            nj = j + d2[k];
            if (ni < 1 || ni > c || nj < 1 || nj > r)
                continue;
            if (map[ni][nj]) {
                q.push({ni, nj});
                distance[ni][nj] = distance[i][j] + 1;
            } 
        }
    }
    cout << "-1\n";
    return 0;
}