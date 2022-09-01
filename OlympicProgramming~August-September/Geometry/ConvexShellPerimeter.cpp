#include "GeometricBase.h"

using namespace std;

struct Point {
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

    double length2() {
        return x * x + y * y;
    }

};

bool comp(Point a, Point b) {
    return ((a ^ b) > 0) || ((a ^ b) == 0 && a.length2() < b.length2());
}

bool condition(Point p, vector<Point>& ch) {
    return ((p - ch[ch.size() - 1]) ^ (ch[ch.size() - 2] - ch[ch.size() - 1])) <= 0;

}

double distance(Point a, Point b) {
    return sqrt((a - b).length2());
}

int main() {

    freopen("hullp.in", "r", stdin);
    freopen("hullp.out", "w", stdout);

    int n;
    cin >> n;

    vector<Point> v;
    vector<Point> ch; // convex huLL

    set<Point> s;
    for (int i = 0; i < n; i++) {
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

    for (auto& p : v) {
        p.x -= p0.x;
        p.y -= p0.y;
    }

    sort(v.begin(), v.end(), comp);

    for (auto p : v) {
        while (ch.size() >= 2 && condition(p, ch)) 
            ch.pop_back();
        ch.push_back(p);
    }

    for (auto& p : ch) 
    {
        p.x += p0.x;
        p.y += p0.y;
    }

    double res = 0;
    for (int i = 0; i < ch.size(); i++) 
        res += distance(ch[i], ch[(i + 1) % ch.size()]);

    cout << fixed << setprecision(16) << res << '\n';

    return 0;
}