#include "GeometricBase.h"

using namespace std;

inline bool const check(vector <int> v, int m, int k) {
    int last = v[0];
    int cnt = 1;
    for (int i = 1; i < v.size(); ++i) 
    {
        if (last + m <= v[i]) 
        {
            last = v[i];
            ++cnt;
        }
    }
    if (cnt < k) return false;
    return true;
}

int main()
{
    freopen("cows.in", "r", stdin);
    freopen("cows.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (auto& x : v) 
        cin >> x;

    int l = -1;
    int r = 1e9;

    while (l < r - 1) 
    {
        int m = (l + r) / 2;
        if (check(v, m, k)) 
            l = m;
        else 
            r = m;
    }

    cout << l << "\n";
    return 0;
}