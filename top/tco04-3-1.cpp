#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <random>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unistd.h>
using namespace std;

#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define len(x) strlen(x)
#define vi vector<int>
#define vs vector<string>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define pvi(x) fora(r, x) cout << r << ' '; cout << '\n'
#define cerr(x) cerr << #x " is " << (x) << endl
#define prt(x, n) fori(i, 0, n) cout << x[i] << " "; cout << "\n"
#define prt2(x, n, m) fori(i, 0, n) {fori(j, 0, m) cout << x[i][j] << " "; \
        cout << "\n"; } cout << "\n"
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double eps = 1e-9;
int cmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Boxing
{
public:
  int maxCredit(vi a, vi b, vi c, vi d, vi e) {
    int credits = 0;
    vi judges[5];
    judges[0] = a;
    judges[1] = b;
    judges[2] = c;
    judges[3] = d;
    judges[4] = e;

    fori(i, 0, 5) 
      cout << sz(judges[i]) << " ";
    cout << "\n";

    vi idx(5, 0);
    int lo = 0; // interval start.
    fori(i, 0, 180001) {
      if (i - lo > 1000) lo = i - 1000;
      int aa = 0;
      fori(j, 0, 5) {
        if (sz(judges[j]) > idx[j]) {
          int time = judges[j][idx[j]];
          // If the jth judge pressed in this time interval.
          if (time>=lo && time<=i)
            ++aa;
        }
      } 
      // If we can give credit.
      if (aa >= 3) {
        cout << "interval: " << lo << " " << i << "\n";
        lo = i + 1;
        ++credits;
      }
      // Remove all times inside this interval, and repeat.
      fori(k, 0, 5) {
        while (sz(judges[k])>idx[k] && judges[k][idx[k]] < lo)
          ++idx[k];
      }
    }  
    return credits;
  }  
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  Boxing go;
  vi a = {1,2,3,4,5,6};
  vi b = {1,2,3,4,5,6,7};
  vi c = {1,2,3,4,5,6};
  vi d = {0,1,2};
  vi e = {1,2,3,4,5,6,7,8};
  int r = go.maxCredit(a, b, c, d, e);
  cout << r << "\n";
  a = {100,200,300,1200,6000};
  b = {};
  c = {900,902,1200,4000,5000,6001};
  d = {0,2000,6002};
  e = {1,2,3,4,5,6,7,8};
  r = go.maxCredit(a, b, c, d, e);
  cout << r << "\n";
  return 0;
}
