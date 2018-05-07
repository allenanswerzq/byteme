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

int jran;
int random(int jlo, int jhi) {
  int im=6075, ia=106, ic=1283;
  jran = (jran * ia + ic) % im;
  int j = jlo + ((jhi - jlo + 1) * jran) / im;
  return j;
}

// Randomly choose numbers not follow any well known distribution.
int random_rand5() {
  int r = 1 + (int) (5.0 * rand() / (RAND_MAX + 1.0));
  return r;
}

int uniform_rand5() {
  int r = random(1, 7);
  while (r > 5)
    r = random(1, 7);
  return r;
}

// int uniform_rand5() {
//   int r = random(1, 10);
//   if (r > 6) {
//     // Do something
//   }
//   return r;
// }

// int main(int argc, char** argv) {
//   std::ios_base::sync_with_stdio(false);
//   return 0;
// }


#include <iostream>
#include <random>
int main(int, char*[]) {
    const int range_from  = 0;
    const int range_to    = 10;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev);
    std::uniform_int_distribution<int>  distr(range_from, range_to);
 
    for (int i = 0; i < 10; ++i)
        std::cout << distr(generator) << '\n';
}