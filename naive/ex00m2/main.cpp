#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool sortBidUser(pair<int, int> l, pair<int, int> r) {
    if (l.second == r.second) {
        return l.first > r.first;
    }
    return l.second > r.second;
}

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    vector<int> items(n);
    map<int, map<int, int>> auction;
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
        auction[i + 1] = map<int, int>();
    }

    char action;
    int u, i, v;
    for (int k = 0; k < a; ++k) {
        cin >> action;
        if (action == 'B') {
            cin >> u >> i >> v;
            auction[i][u] = v;
        } else {
            cin >> u >> i;
            auction[i][u] = -1;
        }
    }

    map<int, vector<int>> map_user_type;
    for (auto item : auction) {
        vector<pair<int, int>> vector_pair_user_bid(item.second.begin(),
                                                    item.second.end());
        sort(vector_pair_user_bid.begin(), vector_pair_user_bid.end(),
             sortBidUser);

        int count = 0;
        int amount = items[item.first - 1];
        for (auto pair_user_bid : vector_pair_user_bid) {
            if (count >= amount) {
                break;
            }
            if (pair_user_bid.second != -1) {
                map_user_type[pair_user_bid.first].push_back(item.first);
                count++;
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        vector<int> vector_type(map_user_type[i]);

        if (map_user_type.find(i) == map_user_type.end() ||
            vector_type.size() == 0) {
            cout << "NONE" << endl;
        }

        else {
            sort(vector_type.begin(), vector_type.end());
            for (auto type : vector_type) {
                cout << type << " ";
            }
            cout << endl;
        }
    }
}
