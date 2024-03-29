#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> visited;
vector<int> order;
void add(int n) {
    // cout << n << endl;
    if (visited[n])
        return;
    for (int i : g[n]) {
        // cout << i << " ";
        if (!visited[i]) {
            add(i);
            if (!visited[i]) {
                visited[i] = true;
                order.push_back(i);
            }
        }
    }
    // cout <<endl;
    if (!visited[n]) {
        visited[n] = true;
        order.push_back(n);
    }
}
void print(){
    for(auto i : g){
        for(auto j : i){
            cout << j << " ";
        }
    cout << endl;
    }
}

int main() {
    int n, tmp, a;
    cin >> n;
    visited = vector<bool>(n, false);
    g = vector<vector<int>>(n);

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp == 0) {
            visited[i] = true;
            order.push_back(i);
        }
        while (tmp--) {
            cin >> a;
            g[i].push_back(a);
        }
    }
    // print();
    for (int i = 0; i < n; ++i) {
        add(i);
    }
    for (auto i : order) {

        cout << i << " ";
    }
    cout << endl;
}