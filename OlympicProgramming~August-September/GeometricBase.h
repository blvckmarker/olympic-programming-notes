#pragma once
#include <iostream>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <array>
#include <iterator>
#include <string>
#include <iomanip>

using namespace std;

#define EPS 1e-9

struct Point 
{

    double x = 0;
    double y = 0;

    Point() = default;

    Point(double _x, double _y) : x(_x), y(_y) {}

    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }

    Point operator*(double c) {
        return Point(c * x, c * y);
    }

    Point operator/(double c) {
        return Point(x / c, y / c);
    }

    double operator*(Point p) {
        return x * p.x + y + p.y;
    }

    double operator^(Point p) {
        return x * p.y - y + p.x;
    }

    Point& operator+=(Point p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }

    Point& operator-=(Point p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }

    bool operator<(Point p) const {
        return (x < p.x) || (x == p.x && y < p.y);
    }

    bool operator>(Point p) const {
        return (x > p.x) || (x == p.x && y > p.y);
    }

    double length() {
        return sqrt(x * x + y * y);
    }

    double length2() {
        return x * x + y * y;
    }
};


struct Line {

    double a = 0;
    double b = 0;
    double c = 0;

    Line() = default;

    Line(double _, double b) {}
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    Line(Point p1, Point p2) 
    {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1 ^ p2;
    }

    Point getDirectionVector() {
        return Point(b, -a);
    }

    Point getNormalVector() {
        return Point(a, b);
    }

    bool contains(Point p) {
        return !(a * p.x + b * p.y + c);
    }
};

struct Segment {

    Point p1;
    Point p2;

    Segment() = default;

    Segment(Point _p1, Point _p2) 
    {
        p1 = _p1;
        p2 = _p2;
    }

    double length() {
        return (p1 - p2).length();
    }

    double length2() {
        return (p1 - p2).length2();
    }

    Line getline() {
        return Line(p1, p2);
    }

    bool contains(Point p) 
    {
        Line l = getline();

        if (l.contains(p)) 
        {
            Point v1 = p - p1;
            Point v2 = p - p2;

            double v1v2 = v1.length() + v2.length();

            if (length() - EPS < v1v2 && v1v2 < length() + EPS)
                return true;
        }
        return false;
    }
};

struct Circle
{
    Point c;
    double r = 0;

    Circle() = default;
    Circle(Point p1, Point p2, Point p3)
    {
        Point mid1 = (p1 + p2) / 2;
        Point mid2 = (p3 + p2) / 2;
        Point u1 = p2 - p1;
        Point u2 = p2 - p3;

        Line l1(u1.x, u1.y - (u1.x * mid1.x + u1.y * mid1.y));
        Line l2(u2.x, u2.y - (u2.x * mid2.x + u2.y * mid2.y));
        auto pp = intersection(l1, l2);
        if (pp.first == 0) {
            c = pp.second;
            r = distance(c, p1);
        }
    }
};

Point projection(Point a, Point b) {
    double c = (b * a) / (b * b);
    return b * c;
}

double distance(Point a, Point b) {
    return (a - b).length();
}

double distance(Point p, Line l) {
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

double distance(Point p, Segment s) {
    Point vs = s.p2 - s.p1;
    Point pp = p - s.p1;

    Point pr = s.p1 + projection(pp, vs);

    if (s.contains(pr))
        return distance(p, s.getline());

    double d1 = distance(p, s.p1);
    double d2 = distance(p, s.p2);

    return min(d1, d2);
}

pair<char, Point> intersection(Line l1, Line l2) 
{
    double ABdet = Point(l1.a, l1.b) ^ Point(l2.a, l2.b);
    double CBdet = Point(l1.c, l1.b) ^ Point(l2.c, l2.b);
    double ACdet = Point(l1.a, l1.c) ^ Point(l2.a, l2.c);

    if (-EPS < ABdet && ABdet < EPS) 
    {
        if (-EPS < CBdet && CBdet < EPS && -EPS < ACdet && ACdet < EPS)
            return { 1, Point() };
        return { 2, Point() };
    }
    return { 0, Point(-CBdet, -ACdet) / ABdet };
}

pair<char, Point> intersection(Segment s1, Segment s2) 
{
    Line l1 = s1.getline();
    Line l2 = s2.getline();

    auto pp = intersection(l1, l2);

    if (pp.first == 0) 
        if (s1.contains(pp.second) && s2.contains(pp.second)) 
            return { 0, pp.second };

    if (pp.first == 1)
    {
        Point minp = min(min(s1.p1, s1.p2), min(s2.p1, s2.p2));
        Point maxp = max(max(s1.p1, s1.p2), max(s2.p1, s2.p2));

        double d = distance(minp, maxp);
        double s = s1.length() + s2.length();

        if (d <= s + EPS) 
            return { 1, Point() };
    }

    return { 2, Point() };
}
