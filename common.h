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
// const double eps = 1e-9;
// int cmp(double x, double y = 0, double tol = eps) {
//   return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
// }

// Count trailing zeros
#define ctz __builtin_ctz
// Count leading zeros
#define clz __builtin_clz
// Count one bits
#define cob __builtin_popcount

// Find all prime numbers in the range of 1 to n, inclusive.
vi sieve(int n) {
  vi primes(n+1, 1);
  // 0 and 1 are not prime number
  primes[0] = 0, primes[1] = 0;

  int m = sqrt(n + 1);
  fori(i, 2, m+1)
    if (primes[i])
      for(int k=i*i; k<=n; k+=i)
        primes[k] = 0;
  return primes;
}

// 
vi rmo(int n) {
  int x = n & ~(n-1);
  int id = ctz(x);
  return {x, id};
}

// Greatest common divisor
// a is greater than b here.
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

// Handle fractions
vi multiply_frac(vi a, vi b) {
  return {a[0]*b[0], a[1]*b[1]}; 
}

vi add_frac(vi a, vi b) {
  int x = lcm(a[1], b[1]);
  return {x/a[1]*a[0] + x/b[1]*b[0], x};
}

vi reduce_frac(vi a) {
  int x = gcd(a[0], a[1]);
  return {a[0]/x, a[1]/x};
}
