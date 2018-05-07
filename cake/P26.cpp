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
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define OUT
#ifdef OUT
#define PR(x) printf x 
#else   
#define PR(x) do { if (0) printf x; } while (0) 
#endif

#define PRT printf
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define FORD(i, a, b) for (int i=(a); i>(b); --i)
#define FORA(e, c) for (auto &e : c)
#define ALL(x) (x).begin(), (x).end()
#define MST(X, v) memset((X), (v), sizeof((X)))
#define LEN(X) strlen(X)
#define VI vector<int>
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void reverse(string& aa) {
  // Case
  if (aa == "") return "";
  int n = aa.size();
  int lo=0, hi=n-1;
  while (lo < hi) {
    swap(aa[lo], aa[hi]);
    ++lo;
    --hi;
  }
}

int main() {
  return 0;
}