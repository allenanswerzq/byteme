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

class BettingMoney {
public:
  int moneyMade(vi& amounts, vi& bb, int ix) {
    long r = 0;
    fora(x, amounts)
      r += x;
    return (r-amounts[ix])*100 - amounts[ix]*bb[ix];
  }
};

vi parse(string s) {
  vi aa;
  int i=1, j=2;
  while (j < sz(s)) {
    while ('0'<=s[j] && s[j]<='9')
      j++;
    int x = stoi(s.substr(i, j-1));
    aa.pb(x);
    i = j+1;
    j = j+2;
  }
  return aa;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  BettingMoney c;
  vi aa, bb;
  int ix;
  string s;
  int i = 0;

  while (cin >> s) {
    ++i;
    if(sz(s) > 1) {
      if (i == 1)
        aa = parse(s);
      if (i == 2)
        bb = parse(s);
    } 
    else ix = stoi(s);

    if (i == 3) { 
      i = 0;
      cout << c.moneyMade(aa, bb, ix) << '\n';
    }
  }
  return 0;
}
