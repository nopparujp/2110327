#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c, coin;
    vector<int> vc;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> coin;
        vc.push_back(coin);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << vc[i] << endl;
    }
}
