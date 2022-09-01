#include "GeometricBase.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    srand(time(nullptr));
    for (int i = 0; i < n; ++i) 
        v[i] = rand() % 10 + 1;

    map<int, int> m;

    for (auto x : v) 
        ++m[x];

    vector<pair<int, int>> items;

    for (auto x : m) 
        items.push_back({ x.second, x.first });

    sort(items.begin(), items.end());

    for (auto x : items) 
        cout << x.second << " " << x.first << "\n";

    return 0;
}