#include "GeometricBase.h"

using namespace std;

inline int const foo(int n) {
    int res = 1;
    for (int i = 2; i * i < n; ++i) 
    {
        int ctn = 0;
        while (n % i == 0) 
        {
            n /= i;
            ++ctn;
        }
        res *= (ctn + 1);
    }
    if (n != 1) 
        res *= 2;

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << foo(n);

    return 0;
}