#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,max_so_far,mx;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ;++i){
        cin >> v[i];
    }
    mx = max_so_far  = v[0] ;
    for (int i = 1 ; i < n ;++i){
        max_so_far = max(max_so_far+v[i] ,v[i]);
        mx = max(max_so_far,mx);
    }
    cout << mx;

}