#include <iostream>
using namespace std;

int countSquares(int k, int cx, int cy, int x, int y)
{
    if (k < 1)
        return 0;
    if (x < cx - k || x > cx + k || y < cy - k || y > cy + k)
        return 0;

    int sub = k / 2;
    return 1
        + countSquares(sub, cx - k, cy - k, x, y)
        + countSquares(sub, cx - k, cy + k, x, y)
        + countSquares(sub, cx + k, cy - k, x, y)
        + countSquares(sub, cx + k, cy + k, x, y);
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;
    cout << countSquares(k, 1024, 1024, x, y) << endl;
    return 0;
}

