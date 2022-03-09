#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> forest;
void print(vector<vector<int>> &v){
    for (auto i:v){
        for(auto j:i){
            cout << j << " " ;
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    forest = vector<vector<int>>(n, vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> forest[i][j];
        }
    }

    // cal
    vector<vector<int>> point = vector<vector<int>>(n, vector<int>(m,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) { 
                point[0][0] = forest[0][0];
            } else if (i == 0 && j > 0)
                point[0][j] += point[0][j - 1] + forest[0][j];
            else if (j == 0 && i > 0)
                point[i][0] += point[i - 1][0] + forest[i][0];
            else

                point[i][j] =
                    max(2 * forest[i][j] + point[i - 1][j - 1],
                        forest[i][j] + max(point[i - 1][j], point[i][j - 1]));
        }
    }
    cout << point[n - 1][m - 1] << endl;
    return 0;
}
