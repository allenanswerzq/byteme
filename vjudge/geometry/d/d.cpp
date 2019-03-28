//============================================================================
// Name        : d
// Date        : Thu Mar 28 15:12:31 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
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
typedef double T;
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
    Point rotate_ccw(double a) {
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
    T A, B, C;
    Line() {}
    Line(Point s, Point e) : s(s), e(e) {}
    void coeff() {
        A = e.y - s.y;
        B = s.x - e.x;
        C = A * s.x + B * s.y;
    }
    friend ostream& operator<<(ostream& os, Line& a) {
        return os << "Line(" << a.s << " " << a.e << ") "
                  << a.A << "x + " << a.B << "y = " << a.C << "\n";
    }
};
bool operator==(Line a, Line b) {
    return !sign((a.s - a.e) ^ (b.s - b.e))
        && !sign((a.s - a.e) ^ (b.s - a.s));
}

void intersect(Line a, Line b) {
    T det = a.A * b.B - b.A * a.B;
    if (!sign(det)) {
        if (a == b) {
            output("LINE");
        } else {
            output("NONE");
        }
    } else {
        T x = (b.B * a.C - a.B * b.C) / det;
        T y = (a.A * b.C - b.A * a.C) / det;
        if (sign(x) == 0) x = 0;
        if (sign(y) == 0) y = 0;
        cout << "POINT " << x << " " << y << "\n";
    }
}

void solve() {
    Line a, b;
    cin >> a.s >> a.e >> b.s >> b.e;
    a.coeff(), b.coeff();
    // trace(a, b);
    intersect(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;

    output("INTERSECTING LINES OUTPUT");
    int t; cin >> t >> ws;
    for (int cs = 1; cs <= t; ++cs) {
        solve();
    }
    output("END OF OUTPUT");
    return 0;
}

