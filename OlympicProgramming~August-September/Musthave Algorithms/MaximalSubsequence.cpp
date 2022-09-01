#include "GeometricBase.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n), dp(n);
    for (auto& x : v) 
        cin >> x;

    dp[0] = 1;

    for (int i = 1; i < n; ++i) 
        if (v[i] > v[i - 1]) 
            dp[i] = dp[i - 1] + 1;
        else 
            dp[i] = 1;

    int res = 0;
    for (int i = 0; i < n; ++i) 
        res = max(res, dp[i]);

    cout << res << "\n";
    return 0;
}