#include "GeometricBase.h"

using namespace std;

#define double long long

struct Point 
{
    double x = 0;
    double y = 0;

    Point() = default;

    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }

    bool operator<(Point p) const {
        return (x < p.x) || (x == p.x && y < p.y);
    }

    double operator^(Point p) {
        return x * p.y - y * p.x;
    }

    double lenght2() {
        return x * x + y * y;
    }
};

bool comp(Point a, Point b) {
    return ((a ^ b) > 0) || ((a ^ b) == 0 && a.lenght2() < b.lenght2());
}

bool condition(Point p, vector<Point>& ch) {
    return ((p - ch[ch.size() - 1]) ^ (ch[ch.size() - 2] - ch[ch.size() - 1])) <= 0;
}

int main() {
    freopen("hull.in", "r", stdin);
    freopen("hull.out", "w", stdout);

    int n;
    cin >> n;

    vector<Point> v;
    vector<Point> ch;

    set<Point> s;

    for (int i = 0; i < n; ++i) 
    {
        Point tmp;
        cin >> tmp.x >> tmp.y;

        if (s.find(tmp) == s.end()) 
        {
            v.push_back(tmp);
            s.insert(tmp);
        }
    }

    Point p0 = v[0];
    for (auto p : v) 
        p0 = min(p, p0);

    for (auto& p : v)
    {
        p.x -= p0.x;
        p.y -= p0.y;
    }

    sort(v.begin(), v.end(), comp);

    for (auto p : v) 
    {
        while (ch.size() >= 2 && condition(p, ch)) 
            ch.pop_back();

        ch.push_back(p);
    }

    for (auto& p : ch) 
    {
        p.x += p0.x;
        p.y += p0.y;
    }

    cout << ch.size() << "\n";

    for (auto p : ch)
        cout << p.x << " " << p.y << "\n";

    return 0;
}