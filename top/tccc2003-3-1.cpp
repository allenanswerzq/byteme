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

class ZigZag {
public: 
  int longestZigZag(vi seqs) {
    int n = sz(seqs);
    if (n <= 2) return n;
    vi dp(n+1, 0), idx(n+1, 0);
    dp[0] = 1, dp[1] = 2; 
    idx[0] = -1, idx[1] = 0;
    fori(i, 2, n) {
      fori(j, 0, i) {
        if (j == 0) dp[i] = 2, idx[i] = 0;
        else if ((seqs[j]-seqs[idx[j]]>0 && seqs[i]-seqs[j]<0) ||
                 (seqs[j]-seqs[idx[j]]<0 && seqs[i]-seqs[j]>0)) {
          dp[i] = dp[j] + 1;
          idx[i] = j;
        }
      }
    }
    return dp[n-1];
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  ZigZag go;
  vi aa = { 1, 7, 4, 9, 2, 5 };
  cout << go.longestZigZag(aa) << '\n';
  aa = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
  cout << go.longestZigZag(aa) << '\n';
  aa = { 44 };
  cout << go.longestZigZag(aa) << '\n';
  aa = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  cout << go.longestZigZag(aa) << '\n';
  aa = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 
        7, 5, 5, 5, 1000, 32, 32 };
  cout << go.longestZigZag(aa) << '\n';
  aa = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
  cout << go.longestZigZag(aa) << '\n';
  return 0;
}
