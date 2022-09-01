#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


struct Point {
    double x = 0;
    int t = 0;
    int i = 0;
    Point() = default;
    Point(double _x, int _t, int _i) {
        x = _x;
        t = _t;
        i = _i;
    }
    bool operator<(Point p) {
        return (x < p.x) || (x == p.x && t < p.t);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Point> v(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i].x;
        v[i].t = i % 2;
        v[i].i = i / 2;
    }
    sort(v.begin(), v.end());
    set<int> s;
    set<pair<int, int>> ans;
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (v[i].t == 0) {
            for (auto& x : s) {
                ans.insert({ min(v[i].i, x), max(v[i].i, x) });
            }
            s.insert(v[i].i);
        }
        if (v[i].t == 1) {
            s.erase(v[i].i);
        }
    }
    for (auto& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}