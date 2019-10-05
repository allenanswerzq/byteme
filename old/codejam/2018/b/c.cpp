#include<bits/stdc++.h>
using namespace std;

vpii cafes;
void build() {
  ll n, v1, h1, a, b, c, d, e, f, m;
  cin >> n >> v1 >> h1 >> a >> b >> c >> d >> e >> f >> m;
  cafes.clear();
  cafes.pb({v1, h1});
  fori (i, 1, n) {
    int v = (a * v1 + b * h1 + c) % m;
    int h = (d * v1 + e * h1 + f) % m;
    // trace(v, h);
    cafes.pb({v, h});
    v1 = v;
    h1 = h;
  } 
}

ll solve() {
  int n = sz(cafes);
  int res = 0;
  unordered_set<string> st;
  fori (i, 0, n) {
    fori (j, i + 1, n) {
      int x1, x2, y1, y2;
      x1 = cafes[i].fi; x2 = cafes[j].fi;
      y1 = cafes[i].se; y2 = cafes[j].se;
      fori (k, 0, n) {
        if (k != i && k != j) {
          int ok = 0;
          int x, y;
          x = cafes[k].fi, y = cafes[k].se;
          int a = min(x1, x2), b = max(x1, x2);
          int c = min(y1, y2), d = max(y1, y2);
          if (a < x && x < b && c < y && y < d) {
            ok = 1;
          }
          else if (a<x && x<b && (y>d || y<c)) { 
            ok = 1;
          }
          else if (c<y && y<d && (x<a || x>b)) {
            ok = 1;
          } else if ((x<a || x>b) && (y>d || y<c)) {
            ok = 1;
          }

          // trace(a, b, c, d, x, y);
          if (ok == 0) {
            vi r = {i, j, k};
            sort(all(r));
            string p = "";
            fori (i, 0, 3) p += (char)(r[i] + '0');
            // trace(r[0], r[1], r[2], p);
            st.insert(p); 
          }
        } 
      } 
    }
  }
  return sz(st);
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    build(); 
    ll r = solve(); 
    output(i, r);
  }

  return 0;
}
