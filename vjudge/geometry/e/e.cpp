//============================================================================
// Name        : e
// Date        : Thu Mar 28 17:25:30 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
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

const double EPS = 1e-8;
int sign(double x) {
    if (x < -EPS) return -1;
    if (x > +EPS) return +1;
    return 0;
}
typedef double T;
struct Point {
    T x, y;
    Point(T x, T y) : x(x), y(y) {}
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

struct Line {
    Point p, q;
    Line(Point x, Point y) : p(x), q(y) {}
};
bool operator==(Line l, Line m) {
    return !sign(cross(l.p - l.q, m.p - m.q)) &&
           !sign(cross(l.p - l.q, m.p - l.p));
}

struct Segment {
    Point p, q;
    Segment(Point x, Point y) : p(x), q(y) {}
};

bool operator==(Segment l, Line m) {
    // do not consider the direction
    return (l.p == m.p && l.q == m.q) || (l.p == m.q && l.q == m.p);
}

bool intersect(Line l, Segment s) {
    T a = cross(s.q - s.p, l.q - l.p);
    T b = cross(l.p - s.p, l.q - l.p);
    if (a < 0) { a *= -1; b *= -1; }
    if (sign(b) < 0 || sign(a - b) < 0) return  0;
    if (sign(a) != 0) return 1;
    if (sign(b) == 0) return 1;
    return 0;
}

T dist(Point p, Point q) {
    return norm(p - q);
}

struct Node {
    int u, v; double w;
};

const int inf = (int)1e9 + 7;
int n, id;
vector<vector<Node> > g;
void dijkstra() {
    typedef pair<double, int> pdi;
    vector<double> dist(id + 1, inf);
    priority_queue<pdi, vector<pdi>, greater<pdi> > dq;
    dq.push({0, 0});
    dist[0] = 0;
    // trace(id, dist);
    while (sz(dq)) {
        pdi tp = dq.top(); dq.pop();
        int u = tp.y;
        // trace(tp);
        // for (auto node : g[u]) {
        for (int i = 0; i < sz(g[u]); ++i) {
            Node node = g[u][i];
            int v = node.v;
            double w = node.w;
            if (sign(dist[v] - (dist[u] + w)) == 1) {
                dist[v] = dist[u] + w;
                dq.push({dist[v], v});
            }
        }
    }
    output(dist[id]);
}

void solve() {
    vector<pair<Point, int> > a;
    vector<Segment> sg;
    id = 0;
    a.pb({{0, 5}, id++});
    for (int i = 1; i <= n; ++i) {
        double x, y1, y2, y3, y4;
        cin >> x >> y1 >> y2 >> y3 >> y4;
        // trace(x, y1, y2, y3, y4);
        a.pb({{x, y1}, id++});
        a.pb({{x, y2}, id++});
        a.pb({{x, y3}, id++});
        a.pb({{x, y4}, id++});
        sg.pb(Segment(Point(x, 0), Point(x, y1)));
        sg.pb(Segment(Point(x, y2), Point(x, y3)));
        sg.pb(Segment(Point(x, y4), Point(x, 10)));
    }
    a.pb({{10, 5}, id});
    // trace(a, sg);

    g = vector<vector<Node> >(id + 1);
    for (int i = 0; i < sz(a); ++i) {
        for (int j = i + 1; j < sz(a); ++j) {
            int u = a[i].y, v = a[j].y;
            Point pu = a[i].x, pv = a[j].x;
            bool ok = 1;
            if (sign(pu.x - pv.x) == 0) {
                continue;
            }
            // We need to check whether there is
            // a direct connection between `u` and `v` or not.
            // for (auto s : sg) {
            for (int k = 0; k < sz(sg); ++k) {
                Segment s = sg[k];
                Line b = Line(pu, pv);
                if (sign(b.p.x - s.p.x) == -1 && sign(s.p.x - b.q.x) == -1) {
                    if (intersect(b, s)) {
                        ok = 0;
                        break;
                    }
                }
            }
            // trace(pu, pv, ok);
            if (ok) {
                double w = dist(pu, pv);
                g[u].pb({u, v, w});
            }
        }
    }
    // trace(g);

    dijkstra();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(2) << fixed;
    while (cin >> n && n != -1) {
        solve();
    }
    return 0;
}

