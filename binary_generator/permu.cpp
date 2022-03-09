#include <bits/stdc++.h>
using namespace std;
#define ll long long
void permu(vector<bool> &v,int i){
    if (i == v.size()){
    for(auto k : v)cout <<k;
    cout << endl;
    return;
    }
    v[i] =0;
    permu(v,i+1);
    v[i] =1;
    permu(v,i+1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> v(3);
    permu(v,0);

}