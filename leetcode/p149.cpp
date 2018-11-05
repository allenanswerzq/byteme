#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

// class Point {
// public:
//   int x;
//   int y;
//   Point() : x(0), y(0) {}
//   Point(int a, int b) : x(a), y(b) {}
//   bool operator < (Point aa) {
//     return x < aa.x; 
//   }
// };

class Solution {
public:
  int maxPoints(vector<Point>& points) {
    int n = sz(points);
    int res = 0;
    unordered_map<ll, int> mp;
    int cur, overlap, vertical;
    fori (i, 0, n) {
      cur = overlap = vertical = 0;
      fori (j, i + 1, n) {
        ll dy = points[j].y - points[i].y;
        ll dx = points[j].x - points[i].x;
        if (dx == 0 && dy == 0) ++overlap;
        else if (dx == 0) ++vertical;
        else {
          int g = __gcd(dx, dy);
          dx /= g;
          dy /= g;
          mp[(dy << 32) | dx]++;
          cur = max(cur, mp[(dy << 32) | dx]);
        }
        cur = max(cur, vertical);
      }
      mp.clear();
      res = max(res, cur + overlap + 1); 
    } 
    return res;
  }
};


int main() {
  return 0;
}
