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
#define vs vector<string>
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

class TallPeople {
public:
  vi getPeople(vector<string>& mat) {
    vector<vi> matrix;
    for (auto row: mat) {
      istringstream iss(row);
      int x;
      vi tmp;
      while (iss >> x) {
        tmp.pb(x);
      }
      matrix.pb(tmp); 
    }
    int r = sz(matrix), c= sz(matrix[0]);
    int rm = INT_MAX, rh = 0;
    fora(row, matrix) {
      fora(x, row) {
        if (x < rm) rm = x;
        if (rm > rh) rh = rm;
      }
    }

    int cm = 0, ch = INT_MAX;
    fori(i, 0, c) {
      fori(j, 0, r) {
        int x = matrix[j][i];
        if (x > cm) cm = x;
        if (cm < ch) ch = cm;
      }
    }

    return {rh, ch};
  };
};

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   return 0;
// }
