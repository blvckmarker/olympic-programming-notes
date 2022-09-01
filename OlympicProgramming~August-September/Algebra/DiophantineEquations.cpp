#include "GeometricBase.h"

using namespace std;

int gcd_full(int a, int b, int& x, int& y) 
{
    if (a == 0) 
    {
        x = 0; y = 1;
        return b;
    }
    int x1;
    int y1;

    int d = gcd_full(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;

    return d;
}

inline bool const diofant(int a, int b, int c, int& x, int& y) 
{
    int d = gcd_full(abs(a), abs(b), x, y);
    if (c % d) 
        return false;

    x *= c / d;
    y *= c / d;

    if (a < 0) x *= -1;
    if (b < 0) y += -1;

    return true;
}


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    bool solved = diofant(a, b, c, x, y);
    if (solved) 
        cout << x << " " << y << "\n";
    else 
        cout << "NO SOLUTION!\n";
    return 0;
}