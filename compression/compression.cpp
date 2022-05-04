#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define iii tuple<int, int, int>
int n, len;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> len;
    vector<string> vi(n);
    vector<string> vs(len);
    for (int i = 0; i < n; ++i) {
        cin >> vi[i];
    }
    for(auto i : vi){
        cout << i << "\n";
    }
    map<string,int> m;
    int c = 0;
    for (int i = 0; i < len; ++i) {
        string tmp;
        for (int j = 0; j < n; ++j){
            tmp += vi[j][i];
        }

        if(m.find(tmp) == m.end()){
           c++; 
           m[tmp] = c;
        }
        cout << m[tmp] << " ";
    
    }
    cout << endl;
}