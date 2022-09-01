#include "GeometricBase.h"

using namespace std;

void get_answer(vector<vector<int>>& dp, vector<int>& w, vector<int>& c, int i, int j) 
{
    if (i == 0) return;

    if (dp[i][j] == dp[i - 1][j]) 
        get_answer(dp, w, c, i - 1, j);
    else 
        if (dp[i][j] == dp[i - 1][j - w[i - 1]] + c[i - 1]) 
        {
            get_answer(dp, w, c, i - 1, j - w[i - 1]);
            cout << i << "\n";
        }
}

int main()
{
    int n, s;
    cin >> n >> s;
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    vector<int> w(n);
    vector<int> c(n);

    for (auto& x : w) 
        cin >> x;

    for (auto& x : c) 
        cin >> x;

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j <= s; ++j) 
        {
            if (dp[i][j] == -1) 
                continue;

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + w[i] < s) 
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + c[i]);
        }
    }
    int res = -1;
    int resj = -1;
    for (int j = 0; j <= s; ++j) 
    {
        if (dp[n][j] > res) 
        {
            res = dp[n][j];
            resj = j;
        }
    }
    cout << res << "\n";
    get_answer(dp, w, c, n, resj);
    return 0;
}