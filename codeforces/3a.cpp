#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(v) cout << (v) << '\n'
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

double tick() {
  static clock_t oldtick;
  clock_t newtick = clock();
  double diff = 1.0 * (newtick - oldtick) / CLOCKS_PER_SEC;
  oldtick = newtick;
  return diff;
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed;

  string a, b; cin >> a >> b;
  int sx = a[0] - 'a', sy = a[1] - '0';
  int dx = b[0] - 'a', dy = b[1] - '0'; 

  // trace(sx, sy, dx, dy);

  if (sx == dx) {
    int ret = abs(dy - sy);
    outret(ret);
    if (dy > sy) {
      fori (i, 0, ret) outret("U"); 
    } else if (dy < sy) {
      fori (i, 0, ret) outret("D");
    }
  } 

  else if (sy == dy) {
    int ret = abs(dx - sx);
    outret(ret);
    if (sx < dx) {
      fori (i, 0, ret) outret("R");
    } else if (sx > dx) 
      fori (i, 0, ret) outret("L");
  } 

  else {
    int c = sx - dx, d = sy - dy;
    int yd = abs(sy - dy), xd = abs(sx - dx);
    int p1 = abs(xd - yd) + yd;
    int p2 = abs(xd - yd) + xd;
    int ret = min(p1, p2);
    outret(ret);
    if (c > 0) {
      if (d > 0) {
        if (p1 < p2) {
          fori (i, 0, yd) outret("LD");
          fori (i, 0, abs(xd - yd)) outret("L"); 
        } else {
          fori (i, 0, xd) outret("LD");
          fori (i, 0, abs(xd - yd)) outret("D"); 
        }
      } else if (d < 0) {
        if (p1 < p2) {
          fori (i, 0, yd) outret("LU");
          fori (i, 0, abs(xd - yd)) outret("L"); 
        } else {
          fori (i, 0, xd) outret("LU");
          fori (i, 0, abs(xd - yd)) outret("U"); 
        }
      }
    } else if (c < 0) {
      if (d > 0) {
        if (p1 < p2) {
          fori (i, 0, yd) outret("RD");
          fori (i, 0, abs(xd - yd)) outret("R"); 
        } else {
          fori (i, 0, xd) outret("RD");
          fori (i, 0, abs(xd - yd)) outret("D"); 
        }

      } else if (d < 0) {
        if (p1 < p2) {
          fori (i, 0, yd) outret("RU");
          fori (i, 0, abs(xd - yd)) outret("R"); 
        } else {
          fori (i, 0, yd) outret("RU");
          fori (i, 0, abs(xd - yd)) outret("U"); 
        }
      }
    }   
  }

  return 0;
}

