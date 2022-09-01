#include "GeometricBase.h"


using namespace std;

inline int const gsd_iter(int a, int b) {
    while (a != 0 && b != 0) 
        if (a > b) 
            a %= b;
        else 
            b %= a;

    return a + b;
}

int gsd_rec(int a, int b) {
    if (a == 0) 
        return b;
    return gsd_rec(b % a, a);
}

int gcd_full(int a, int b, int& x, int& y) {
    if (a == 0) {
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

#define ITER_GSD 1

int main()
{
    int a, b, x ,y;
    cin >> a >> b;

#if ITER_GSD
    cout << gsd_iter(a, b) << "\n";
#elif REC_GSD
    cout << gsd_rec(a, b) << "\n";
#else
    cout << gcd_full(a, b, x, y) << "\n";
    cout << x << " " << y << "\n";
#endif

    return 0;
}