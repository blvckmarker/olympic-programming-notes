#include "GeometricBase.h"

using namespace std;

int main()
{
    freopen("collect.in", "r", stdin);
    freopen("collect.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto& x : v) 
        cin >> x;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) 
    {
        int x;
        cin >> x;

        int l = -1;
        int r = n - 1;

        while (l < r - 1) 
        {
            int mid = (l + r) / 2;
            if (v[mid] < x) 
                l = mid;
            else 
                r = mid;
        }

        if (v[r] == x) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}