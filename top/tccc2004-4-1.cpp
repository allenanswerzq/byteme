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
#define mst(x, n, v) fori(i, 0, n) x[i] = v
#define mst2(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
#define mst3(x, n, m, c, v) \
        fori(i, 0, n) \
          fori(j, 0, m) \
            fori(k, 0, c) \
              x[i][j][k] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
// TDOD
class BadNeighbors {
public:
  int maxDonations(vi aa) {
    int n = sz(aa);
    vi dp1(n+1, 0), dp2(n+1, 0);
    dp1[0] = aa[0];
    dp2[1] = aa[1];

    int res = 0;
    // Note: not reach to the last one person,
    // Because we include the first person here.
    fori(i, 0, n-1) {
      int r = 0;
      fori(j, 0, i-1)
        if (r < dp1[j]) r = dp1[j];
      dp1[i] = aa[i] + r;
      pvi(dp1);
      res = max(res, dp1[i]);
    }
    // Note: not include the first person,
    // Because we use the last person's money.
    fori(i, 1, n) {
      int r = 0;
      fori(j, 1, i-1)
        if (r < dp2[j]) r = dp2[j];
      dp2[i] = aa[i] + r;
      pvi (dp2);
      res = max(res, dp2[i]);
    }
    return res;

  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  BadNeighbors go;
  vi   aa = { 10, 3, 2, 5, 7, 8 };
  cout << go.maxDonations(aa) << '\n';
  aa = { 11, 3 };
  cout << go.maxDonations(aa) << '\n';
  // aa = { 7, 7, 7, 7, 7, 7, 7 };
  // cout << go.maxDonations(aa) << '\n';
  aa = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
  cout << go.maxDonations(aa) << '\n';
  // aa = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  // 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  // 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
  // cout << go.maxDonations(aa) << '\n';
  return 0;
}
