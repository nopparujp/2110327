#include <bits/stdc++.h>
using namespace std;

vector<int> v,table;
int cal(int start) {
    if (start >= v.size())
        return table[v.size()-1];
    if (table[start] != 0){
        return table[start];
    }

    table[start]= max({
        v[start] + cal(start + 1), 
        v[start] + cal(start + 2),         
        v[start] + cal(start + 3)});

    return table[start];
}
int main() {

    int n;
    cin >> n;
    v = vector<int>(n);
    table = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << cal(0);
}