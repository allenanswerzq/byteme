//============================================================================
// Name        : c
// Date        : Thu Mar 28 10:45:12 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mst(x, y) memset(x, y, sizeof(x))
#define pvar(x) cout << #x << ": "
#define output(v) cout << (v) << '\n'
#define fori(i, a, b) for (int i = a; i < b; ++i)
#define jam(x, n) cout << "Case #" << x << ": " << n << "\n"
#define prt(x, a, n) { cout << x[a]; if (a < n - 1) cout << " "; }
#define par(x, s, n, v) if(v) pvar(x); fori(y, s, n) prt(x, y, n) cout << "\n"

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const double PI = acos(-1.0);
const double EPS = 1e-8;
int sign(double x) {
    if (x < -EPS) return -1;
    if (x > +EPS) return +1;
    return 0;
}

typedef long double T;
struct Point {
    T x, y;
    Point() {}
    Point(T x, T y) : x(x), y(y) {}
    Point &operator+=(Point p) { x += p.x; y += p.y; return *this; }
    Point &operator-=(Point p) { x -= p.x; y -= p.y; return *this; }
    Point &operator*=(T a) { x *= a; y *= a; return *this; }
    Point &operator/=(T a) { return *this *= (1.0/a); }
    Point operator-() const { return {-x, -y}; }
    double operator^(const Point &b) const { return x * b.y - y * b.x; }
    double operator*(const Point &b) const { return x * b.x + y * b.y; }
    bool operator<(Point p) const {
        int s = sign(x - p.x);
        return s ? s < 0 : sign(y - p.y) < 0;
    }
    // Returns point rotated `a` degree ccw around the origin point.
    Point rotate(double a) {
        return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
};
bool operator==(Point p, Point q) { return !(p < q) && !(q < p); }
bool operator!=(Point p, Point q) { return p < q || q < p; }
bool operator<=(Point p, Point q) { return !(q < p); }
Point operator+(Point p, Point q) { return p += q; }
Point operator-(Point p, Point q) { return p -= q; }
Point operator/(Point p, T a) { return p /= a; }
Point orth(Point p) { return {-p.y, p.x}; }
T dist(Point a, Point b) { return sqrt((b - a) * (b - a)); }
T norm2(Point p) { return p * p; }
T norm(Point p) { return sqrt(p * p); }
T arg(Point p) { return atan2(p.y, p.x); }
T arg(Point p, Point q) { return atan2(p ^ q, p * q); }
istream& operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
ostream& operator<<(ostream &os, const Point &p) {
    return os << "Point(" << p.x << ", " << p.y << ")";
}

struct Line {
    Point s, e;
    Line() {}
    Line(Point s, Point e) : s(s), e(e) {}
    friend ostream& operator<<(ostream& os, Line& a) {
        return os << "Line(" << a.s << " " << a.e << ")\n";
    }
};

double half(Point a, Point b, Point c) {
    return (b - a) ^ (c - a);
}

// If a seg `a` is intersects with a line `b`.
bool seg_line_intersect(Line a, Line b) {
    return sign(half(a.s, b.s, b.e)) * sign(half(a.e, b.s, b.e)) <= 0;
}

// Ref: http://poj.org/showmessage?message_id=100149:

int n;
vector<Line> a;
bool check(Line b) {
    if (sign(dist(b.s, b.e)) == 0) {
    // If this line only has one point, then it can't make a desirable line
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (seg_line_intersect(a[i], b) == 0) {
            return 0;
        }
    }
    // Returns 1 only when this line can intersect with all other segs.
    return 1;
}

void solve() {
    cin >> n;
    a = vector<Line>(n);
    for (int i = 0; i < n; ++i) {
        Point s, e;
        cin >> s >> e;
        a[i] = Line(s, e);
    }
    // trace(a);
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (check(Line(a[i].s, a[j].s)) ||
                check(Line(a[i].s, a[j].e)) ||
                check(Line(a[i].e, a[j].s)) ||
                check(Line(a[i].e, a[j].e)) ) {
                ok = 1;
                break;
            }
        }
    }
    output(ok ? "Yes!" : "No!");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t >> ws;
    fori (i, 1, t + 1) {
        solve();
    }
    return 0;
}

