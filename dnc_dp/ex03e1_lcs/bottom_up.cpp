#include <iostream>
#include <string>
using namespace std;

string A, B;
int table[500][500];

int main() {
    cin >> A >> B;

    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            if (A[i] == B[j]) {
                if (i - 1 < 0 || j - 1 < 0)
                    table[i][j] = 1;
                else
                    table[i][j] = table[i - 1][j - 1] + 1;
            } else
                table[i][j] =
                    max(table[i][max(j - 1, 0)], table[max(i - 1, 0)][j]);
        }
    }

    cout << table[A.size() - 1][B.size() - 1] << endl;
}
