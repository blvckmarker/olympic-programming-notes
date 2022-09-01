#include "GeometricBase.h"

using namespace std;

int Fibonacci(int a[2][2], int n) //log (n)
{
    int res[2][2];
    int b[2][2];

    res[0][0] = 1; res[0][1] = 0;
    res[1][1] = 1; res[1][0] = 0;

    while (n)
    {
        if (n & 1) 
        {
            for (int i = 0; i < 2; ++i) 
            {
                for (int j = 0; j < 2; ++j) 
                {
                    b[i][j] = 0;
                    for (int k = 0; k < 2; ++k) 
                        b[i][j] += res[i][k] * a[k][j];
                }
            }
            res[0][0] = b[0][0]; res[0][1] = b[0][1];
            res[1][0] = b[1][0]; res[1][1] = b[1][1];
        }

        for (int i = 0; i < 2; ++i) 
        {
            for (int j = 0; j < 2; ++j) 
            {
                b[i][j] = 0;
                for (int k = 0; k < 2; ++k) 
                    b[i][j] += a[i][k] * a[k][j];
            }
        }

        a[0][0] = b[0][0]; a[0][1] = b[0][1];
        a[1][0] = b[1][0]; a[1][1] = b[1][1];
        n >>= 1;
    }
    return res[0][1];
}

vector<int> v;
int Fibonacci(int n) {
    if (v[n] != 0) 
        return v[n];

    v[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return v[n];
}

#define LOGN 1
int main()
{
    int a[2][2], n;
    a[0][0] = 1; a[0][1] = 1;
    a[1][0] = 1; a[1][1] = 0;
#if LOGN
    cout << Fibonacci(a, 10) << "\n";
#else
    cin >> n;
    v.resize(n + 1, 0);
    v.at(0) = 1;
    v.at(1) = 1;

    cout << Fibonacci(n - 1) << "\n";
#endif
    return 0;
}