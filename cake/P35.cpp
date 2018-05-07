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

// Non-deterministic
int random_random(int lo, int hi) {
  random_device rd;
  uniform_int_distribution<int> dist(lo, hi);
  return dist(rd);
}

vi shuffle(vector<int>& a) {
  int n = sz(a), l=n;
  vi res(n, 0), v(a);

  fori(i, 0, n) {
    int choice = random_random(0, l-1);
    res[i] = v[choice];
    v.erase(v.begin() + choice);
    l = sz(v);
  }
  return res;
}

vi shuffle_in_place(vi& a) {
  int n = sz(a);
  fori(i, 0, n-1) {
    int choice = random_random(i, n-1);
    if (i != choice)
      swap(a[i], a[choice]);
  }
  return a;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  // Choose a random seed
  jran = 200;
  vi v = {1, 2, 3, 4, 5};
  vi vv = shuffle(v);
  fora(x, vv)
    cout << x << ' ';
  cout << '\n';

  vv = shuffle_in_place(v);
  fora(x, vv)
    cout << x << ' ';
  cout << '\n';
  return 0;
}