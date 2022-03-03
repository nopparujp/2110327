#include <bits/stdc++.h>
using namespace std;
int search (vector<int> &v , int query){
    int begin = 0,end = v.size() -1,mid;
    if (v[0]>query)return -1;
    if (v[end] <= query)return v[end];
    while (end - begin > 1){
        mid = (end + begin) >> 1;
        if(v[mid] > query) end = mid;
        else begin = mid;
    }
    return v[begin];
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m,query;
    cin >> n >> m ;
    vector<int> v(n);
    for (int i = 0 ; i< n ;++i){
        cin >> v[i];
    }
    for (int i = 0; i < m;++i){
        cin >> query ;
        cout << search(v,query) << "\n";
    }
}