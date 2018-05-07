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
#define cerr(x) cerr << #x " is " << (x) << endl
#define mst(x, n, m, v) fori(i, 0, n) fori(j, 0, m) x[i][j] = v
const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int mem[10][10];

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  // for (float i=0.0; i<=2.0; i+=0.01) {
  //   printf("%f\n", i);
  // }
  // mst(mem, 10, 10, 2);
  memset(mem, -2, sizeof mem);
  fori(i, 0, 10)
    fori(j, 0, 10)
      cout << mem[i][j] << ' ';

  // printf("=>\n");
  // printf("%f\n", (3.14 + 1e20) - 1e20);
  // printf("%f\n", 3.14 + (1e20 - 1e20));
  // printf("%f\n", (3.14 + 1e10) - 1e10);
  // printf("%f\n", 3.14 + (1e10 - 1e10));

  // // Effects of c promotion rules
  // printf("=>\n");
  // printf("%d\n", -1 < 0u);
  // printf("%d\n", -1 < 0);

  // printf("=>\n");
  // printf("%d\n", 2147483647 > -2147483647-1);
  // printf("%d\n", 2147483647u > -2147483647-1);
  // printf("%x %x\n", 2147483647, -2147483647-1);
  // printf("%d\n", (int)2147483648u);

  return 0;
}
