#include <bits/stdc++.h>
using namespace std;

pair<int, int> findJK(vector<int> v, int i)
{
    int j = i - 1;
    int k = i + 1;
    while (v[j] == 0)
    {
        --j;
    }
    while (v[k] == 0)
    {
        ++k;
    }
    return make_pair(j, k);
}

int countMul(vector<int> v, const vector<int> &com)
{
    int sum = 0;

    for (int i : com)
    {
        pair<int, int> p = findJK(v, i + 1);
        sum += v[i + 1] * v[p.first] * v[p.second];
        v[i + 1] = 0;
    }

    return sum;
}

void permu(vector<int> &com, int pos, int m, vector<bool> &used, vector<int> v,
           int &min_mul)
{
    if (pos < com.size())
    {
        for (int i = 0; i < m; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                com[pos] = i;
                permu(com, pos + 1, m, used, v, min_mul);
                used[i] = false;
                com[pos] = 0;
            }
        }
    } else
    {
        min_mul = min(countMul(v, com), min_mul);
    }

    return;
}

int main()
{
    int n, min_mul = INT_MAX;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> com(n - 1);
    vector<bool> used(n - 1, 0);

    for (int i = 0; i < n + 1; ++i)
    {
        cin >> v[i];
    }


    permu(com, 0, n - 1, used, v, min_mul);

    cout << min_mul << endl;

    return 0;
}
