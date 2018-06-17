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

class FairWorkload
{
public:
  // Predicate: Can x folders be assigned to each worker, with the limited 
  // number of workers available?
  // If assign x can, then all number greater than x also can. and x might be 
  // the minimum number of the maximum number of folders that can be assigned.
  int getMostWork(vi folders, int workers) {
    int n = sz(folders);
    int lo = *max_element(all(folders));
    int hi = accumulate(all(folders), 0); 

    while (lo < hi) {
      int x = lo + (hi - lo)/2;

      int required = 1, curr_folders = 0;
      fori(i, 0, n) {
        if (curr_folders + folders[i] <= x)
          curr_folders += folders[i];
        else {
          ++required;
          curr_folders = folders[i];
        }
      }

      if (required <= workers) 
        hi = x;
      else
        lo = x + 1;
    }

    return lo;
  }  

};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vi aa = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  FairWorkload go;
  cout << go.getMostWork(aa, 3) << "\n";
  return 0;
}
