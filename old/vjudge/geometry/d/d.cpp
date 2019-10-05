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
    Point &operator+=(Point p) { x += p.x; y += p.y; return *this; }
    Point &operator-=(Point p) { x -= p.x; y -= p.y; return *this; }
    Point &operator*=(T a)     { x *= a;   y *= a;   return *this; }
    Point &operator/=(T a)     { return *this *= (1.0 / a); }
    Point operator-() const    { return {-x, -y}; }
    bool operator<(Point p) const {
        int s = sign(x - p.x);
        return s ? s < 0 : sign(y - p.y) < 0;
    }
};
bool operator==(Point p, Point q) { return !(p < q) && !(q < p); }
bool operator!=(Point p, Point q) { return p < q || q < p; }
bool operator<=(Point p, Point q) { return !(q < p); }
Point operator+(Point p, Point q) { return p += q; }
Point operator-(Point p, Point q) { return p -= q; }
Point operator*(T a, Point p) { return p *= a; }
Point operator*(Point p, T a) { return p *= a; }
Point operator/(Point p, T a) { return p /= a; }
T dot(Point p, Point q) { return p.x * q.x + p.y * q.y; }
T cross(Point p, Point q) { return p.x * q.y - p.y * q.x; }
T norm2(Point p) { return dot(p, p); }
Point orth(Point p) { return {-p.y, p.x}; }
T norm(Point p) { return sqrt(dot(p, p)); }
T arg(Point p) { return atan2(p.y, p.x); }
T arg(Point p, Point q){ return atan2(cross(p, q), dot(p, q)); }
istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, Point &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

struct Line { Point p, q; };
bool operator==(Line l, Line m) {
    return !sign(cross(l.p - l.q, m.p - m.q)) &&
           !sign(cross(l.p - l.q, m.p - l.p));
}

vector<Point> intersect(Line l, Line m) {
    vector<Point> ret;
    T a = cross(m.q - m.p, l.q - l.p);
    T b = cross(l.p - m.p, l.q - l.p);
    if (sign(a)) {
        ret.pb(m.p + b / a * (m.q - m.p));
        return ret;
    }
    if (!sign(b)) {
        ret.pb(m.p);
        ret.pb(m.q);
    }
    return ret;
}

T dist(Point p, Point q) {
    return norm(p - q);
}

void solve() {
    Line a, b;
    cin >> a.p >> a.q >> b.p >> b.q;
    vector<Point> ret = intersect(a, b);
    int n = sz(ret);
    if (n == 0) {
        output("NONE");
    } else if (n == 2) {
        output("LINE");
    } else {
        cout << "POINT " << ret[0].x << " " << ret[0].y << "\n";
    }
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

