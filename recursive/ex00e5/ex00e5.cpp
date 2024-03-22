#include <bits/stdc++.h>
using namespace std;

void sol(vector<int> &v, int n, int k, int pos, int c, int done)
{
    if (pos == n)
    {
        if (done == 1)
        {
            for (int &i : v)
            {
                cout << i;
            }
            cout << endl;
        }
        return;
    }

    v[pos] = 0;
    sol(v, n, k, pos + 1, 0, done);

    v[pos] = 1;
    sol(v, n, k, pos + 1, c + 1, done || c + 1 >= k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    sol(v, n, k, 0, 0, 0);
}
