#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> forest(n);
    for (int i = 0; i < n; ++i) {
        cin >> forest[i];
    }
    vector<int> start;
    for (int i = 0; i < k; ++i) {
        int tmp;
        cin >> tmp;
        start.push_back(tmp);
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<bool> visited(n,0);
    for(auto s : start){
        queue<int>q;
        q.push(s);
        visited[s] = true;
        forest[s]  = 0;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto ncur : g[cur]){
                if(!visited[ncur]){
                    q.push(ncur);
                    forest[ncur]  = 0;
                    visited[ncur] = true;
                }
            }
        }
        int sm = 0;
        for(auto i : forest){
            sm += i;
        }
        cout << sm << " ";
    }
}