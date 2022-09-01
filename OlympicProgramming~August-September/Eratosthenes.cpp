#include "GeometricBase.h"

using namespace std;

inline void const sieve(int n) 
{
    vector<bool> u(n + 1, true);

    u[0] = false;
    u[1] = false;

    for (int i = 2; i <= n; ++i) 
        if (u[i]) 
            if (i * 1LL * i <= n) 
                for (int j = i * i; j <= n; j += i) 
                    u[j] = false;

    for (int i = 0; i <= n; ++i) 
        if (u[i]) 
            cout << i << " ";

    cout << "\n";
}

int main()
{
    int n;
    cin >> n;

    sieve(n);

    return 0;
}