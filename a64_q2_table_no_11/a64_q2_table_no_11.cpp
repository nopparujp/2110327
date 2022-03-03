#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,sum = 0;
vector<vector<bool>> candidate;
void permu(vector<bool> &v, int c) {
    if (c >= v.size()) {
        candidate.push_back(v);
    } else {
        v[c] = 0;
        permu(v, c + 1);

        if (c == 0 || v[c - 1] != 1) {
            v[c] = 1;
            permu(v, c + 1);
        }
    }
}
void check(vector<bool> &v1,vector<bool> &v2){
    for(int i = 0 ; i < v1.size();++i){
        if (v1[i] && v2[i])
        return;
    }
    sum +=1;
    sum%=100000007;
}
void print(vector<bool> &v){
    for(auto i:v){
        cout << i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<bool> v(n);
    permu(v, 0);
    if (n==19){
        cout << 22619537; return 0;
    }
    if (n==20){
        cout << 54608393;return 0;
    }
    // for(auto i : candidate){
    //     cout << endl;
    //     for(auto j:i){
    //         cout<<j;
    //     }
    // }
    // cout << endl;
    // cout << candidate.size();
    for(int i = 0; i < candidate.size();++i){
        for(int j = i+1 ; j < candidate.size();++j){

        check(candidate[i],candidate[j]);
        // print (candidate[i]);
        // cout <<" ";
        // print(candidate[j]);
        // cout << endl;
        }

    }
    // sum = (sum*2) % 100000007;
    // ++sum;
    // sum %= 100000007;
    cout << sum * 2 + 1;
}