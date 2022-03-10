#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k,con =1e8+7;
vector<ll> v_base(4);
vector<ll> mul_b(vector<ll> v){
    int a,b,c,d,w,x,y,z;
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    w = v_base[0];
    x = v_base[1];
    y = v_base[2];
    z = v_base[3];
    return {
        (a*w+b*y)%k,
        (a*x+b*z)%k,
        (c*w+d*y)%k,
        (c*x+d*z)%k,
    };
    
}
vector<ll> mul2(vector<ll> &v){
    ll a,b,c,d;
    a = v[0];
    b = v[1];
    c = v[2];
    d = v[3];
    return {
        (a*a+b*c)%k,
        (a*b+b*d)%k,
        (a*c+d*c)%k,
        (b*c+d*d)%k};
}

vector<ll> sol(vector<ll> v, int power, int k) {
    if (power == 1) {
        return v;
    }
    ll s = power/2;
    vector<ll> tmp = sol(v,s,k);
    if(power %2 != 0){
        return mul_b(mul2(tmp));
    }
    else{
        return mul2(tmp);
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (ll i = 0; i < 4; ++i) {
        cin >> v_base[i];
    }
    vector<ll> o = sol(v_base,n,k);
    for(auto i : o){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}