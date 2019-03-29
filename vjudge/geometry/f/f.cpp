//============================================================================
// Name        : f
// Date        : Fri Mar 29 10:26:46 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
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
    // do not consider the direction
    return (l.p == m.p && l.q == m.q) || (l.p == m.q && l.q == m.p);
}

bool intersect(Segment a, Segment b) {
    double c1 = cross(a.q - a.p, b.p - a.p), c2 = cross(a.q - a.p, b.q - a.p);
    double c3 = cross(b.q - b.p, a.p - b.p), c4 = cross(b.q - b.p, a.q - b.p);
    return sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0;
}

// Still not accepted...

int n;
void solve() {
    vector<Segment> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf%lf", &a[i].p.x, &a[i].p.y, &a[i].q.x, &a[i].q.y);
    }
    vi top(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (intersect(a[i], a[j])) {
                top[i] = 0;
                break;
            }
        }
    }
    cout << "Top sticks: ";
    for (int i = 0; i < sz(top); ++i) {
        if (top[i] == 1) {
            cout << i + 1;
            if (i == sz(top) - 1) {
                cout << ".\n";
            } else {
                cout << ", ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> n && n) {
        solve();
    }
    return 0;
}

