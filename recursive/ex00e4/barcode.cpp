#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
    }
    cout << endl;
}
void gen(int a, int b, int i, vector<int> &v, int sum)
{
    if (i < b)
    {
        v[i] = 0;
        gen(a, b, i + 1, v, sum);
        if (sum < a)
        {

            v[i] = 1;
            gen(a, b, i + 1, v, sum + 1);
        }
    } else if (sum == a)
    {
        print(v);
    }
    return;
}
int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> v(b, 0);
    gen(a, b, 0, v, 0);
}
// input 2 4
// output
// 1100
// 1010
// 1001
// 0101
// 0110
// 0011