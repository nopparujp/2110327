#include <iostream>
using namespace std;
#define vi
void tile(int l, int x, int y, int x1, int x2, int y1, int y2) {
    if (l < 2) {
        return;
    }

    l >>= 1;
    int mx = (x1 + x2) >> 1;
    int my = (y1 + y2) >> 1;

    if (x > mx && y > my) {
        cout << "3 " << mx << " " << my << endl;
        tile(l, mx, my, x1, mx, y1, my);
        tile(l, mx + 1, my, mx + 1, x2, y1, my);
        tile(l, mx, my + 1, x1, mx, my + 1, y2);
        tile(l, x, y, mx + 1, x2, my + 1, y2);
    } else if (x > mx && y <= my) {
        cout << "1 " << mx << " " << my << endl;
        tile(l, mx, my, x1, mx, y1, my);
        tile(l, x, y, mx + 1, x2, y1, my);
        tile(l, mx, my + 1, x1, mx, my + 1, y2);
        tile(l, mx + 1, my + 1, mx + 1, x2, my + 1, y2);
    } else if (x <= mx && y > my) {
        cout << "2 " << mx << " " << my << endl;
        tile(l, mx, my, x1, mx, y1, my);
        tile(l, mx + 1, my, mx + 1, x2, y1, my);
        tile(l, x, y, x1, mx, my + 1, y2);
        tile(l, mx + 1, my + 1, mx + 1, x2, my + 1, y2);
    } else if (x <= mx && y <= my) {
        cout << "0 " << mx << " " << my << endl;
        tile(l, x, y, x1, mx, y1, my);
        tile(l, mx + 1, my, mx + 1, x2, y1, my);
        tile(l, mx, my + 1, x1, mx, my + 1, y2);
        tile(l, mx + 1, my + 1, mx + 1, x2, my + 1, y2);
    }
}

int main() {
    int L, X, Y;
    cin >> L >> X >> Y;
    cout << L * L / 3 << endl;
    tile(L, X, Y, 0, L - 1, 0, L - 1);
}
