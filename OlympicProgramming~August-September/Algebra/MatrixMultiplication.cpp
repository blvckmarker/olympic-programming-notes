#include "GeometricBase.h"

using namespace std;

vector<vector<int>> mat_mult(vector<vector<int>>& m1, vector<vector<int>>& m2)
{

    int n = m1.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            res[i][j] = 0;
            for (int k = 0; k < n; ++k) 
                res[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return res;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> m1(n, vector<int>(n, 0));
    vector<vector<int>> m2(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> m1[i][j];

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            cin >> m2[i][j];

    auto m3 = mat_mult(m1, m2);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << m3[i][j] << " ";
        cout << "\n";
    }
	return 0;
}