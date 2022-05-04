#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
#define vvi vector<vector<int>>
set<vector<vector<int>>> done;
struct CustomCompare {
    bool operator()(const pair<pii, vvi> &lhs, const pair<pii, vvi> &rhs) {
        return lhs.first.first < rhs.first.first;
    }
};
class Compare {
  public:
    bool operator()(pair<pii, vvi> &l, pair<pii, vvi> &r) {
        return l.first.first > r.first.first;
    }
};
priority_queue<pair<pii, vvi>, vector<pair<pii, vvi>>, Compare> q;

int check(vector<vector<int>> table) {
    int r = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table[i][j] == 0)
                continue;
            int tx = (table[i][j] - 1) % 4;
            int ty = (table[i][j] - 1) / 4;
            r += abs(ty - i) + abs(tx - j);
        }
    }
    return r;
}
bool check_s(vvi table1, vvi table2) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (table1[i][j] != table2[i][j])
                return false;
        }
    }
    return true;
}

void cal(vector<vector<int>> table) {
    q.push({{check(table), 0}, table});
    while (!q.empty()) {
        auto cur_table = q.top().second;
        auto round = q.top().first.second;
        q.pop();
        if (done.find(cur_table) == done.end()) {
            done.insert(cur_table);
            int pri = check(cur_table);
            if (pri == 0) {
                cout << round << endl;
                return;
            }
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (cur_table[i][j] == 0) {
                        // move up
                        if (i != 0) {
                            auto new_table = cur_table;
                            swap(new_table[i][j], new_table[i - 1][j]);
                            q.push({{check(new_table) + round + 1, round + 1},
                                    new_table});
                        }
                        // move down
                        if (i != 3) {
                            auto new_table = cur_table;
                            swap(new_table[i][j], new_table[i + 1][j]);
                            q.push({{check(new_table) + round + 1, round + 1},
                                    new_table});
                        }
                        // move left
                        if (j != 0) {
                            auto new_table = cur_table;
                            swap(new_table[i][j], new_table[i][j - 1]);
                            q.push({{check(new_table) + round + 1, round + 1},
                                    new_table});
                        }
                        // move right
                        if (j != 3) {
                            auto new_table = cur_table;
                            swap(new_table[i][j], new_table[i][j + 1]);
                            q.push({{check(new_table) + round + 1, round + 1},
                                    new_table});
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> table(4, vector<int>(4));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> table[i][j];
        }
    }
    cal(table);
}