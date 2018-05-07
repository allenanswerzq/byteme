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
using namespace std;

#define debug

#ifdef debug
#define pr(x) printf x 
#else   
#define pr(x) do { if (0) printf x; } while (0) 
#endif

#define prt printf
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define fora(e, c) for (auto &e : c)
#define all(x) (x).begin(), (x).end()
#define mst(X, v) memset((X), (v), sizeof((X)))
#define len(X) strlen(X)
#define vi vector<int>
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define cerr(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// This approach destorys our input.
int findDuplicate(vi& v) {
  if (v.empty()) return -1;
  sort(all(v));
  int n = sz(v);
  int lo=0, hi=1;
  while (hi < n) {
    int p = 1;
    while (hi<n && v[hi] == v[lo]) {
      hi++;
      p++;
    }
    if (p > 1) 
      return v[lo];
    lo = hi;
    ++hi;
  }
  return -1;
}

unsigned int findRepeat(const vi& theVector)
{
  unsigned int lo = 1;
  unsigned int hi = theVector.size() - 1;

  while (lo < hi) {

    unsigned int mid = lo + ((hi - lo) / 2);
    // Scan the whole vector and find out 
    // all the numbers belong to lo->mid range
    unsigned int cnt = 0;
    for (unsigned int item : theVector) {
      if (lo <= item && item <= mid) {
        ++cnt;
      }
    }
    // Assume all numbes in range lo->mid are distinct.
    // Range lo->mid can only hold this number of numbers. 
    unsigned int distinct_cnt = mid - lo + 1;

    //cout << "mid: " << mid << " cnt: " << cnt 
    // << " d: " << distinct_cnt << '\n';
    if (cnt > distinct_cnt) {
      // There must have some number in range lo->mid duplicated.
      hi = mid;
    }
    else {
      // Since the whole vector has the number belong to range lo->mid
      // equals the number in this range. So there is no duplicate 
      // in lo->mid range.
      lo = mid+1;
    }
  }

  return lo;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vi a = {0, 1, 4, 2, 3, 2};
  cout << findDuplicate(a) << '\n';
  cout << findRepeat(a) << '\n';
  return 0;
}
