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

struct Segment { Point p, q; };
bool operator==(Segment l, Line m) {
    return (l.p == m.p && l.q == m.q) || (l.p == m.q && l.q == m.p);
}

bool intersect(Line l, Segment s) {
    T a = cross(s.q - s.p, l.q - l.p);
    T b = cross(l.p - s.p, l.q - l.p);
    if (a < 0) { a *= -1; b *= -1; }
    if (sign(b) < 0 || sign(a - b) < 0) {
        return 0;
    }
    if (sign(a) != 0) {
        return 1;
    }
    if (sign(b) == 0) {
        return 1;
    }
    return 0;
}

T dist(Point& p, Point& q) {
    return norm(p - q);
}

int n;
vector<Segment> a;
bool check(Line b) {
    if (sign(dist(b.p, b.q)) == 0) {
    // If this line only has one point, then it can't make a desirable line
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (intersect(b, a[i]) == 0) {
            return 0;
        }
    }
    // Returns 1 only when this line can intersect with all other segs.
    return 1;
}

void solve() {
    cin >> n;
    a = vector<Segment>(n);
    for (int i = 0; i < n; ++i) {
        Point s, e;
        cin >> s >> e;
        a[i] = {s, e};
    }
    // trace(a);
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (check(Line{a[i].p, a[j].p}) ||
                check(Line{a[i].p, a[j].q}) ||
                check(Line{a[i].q, a[j].p}) ||
                check(Line{a[i].q, a[j].q}) ) {
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

