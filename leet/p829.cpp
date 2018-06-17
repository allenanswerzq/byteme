#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <vector>
#include <random>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <climits>
#include <cassert>
#include <fstream>
#include <sstream>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf pop_front
#define ppb pop_back
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int, int>

#define len(x) strlen(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cerr(x) cerr << #x " is " << (x) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int consecutiveNumbersSum(int N) {
    if (N == 1) return 1;
    int n = sqrt(2 * N) + 1;     
    int res = 0;
    fori(i, 1, n+1) {
      int t = N - i * (i-1) / 2;
      if (t && i<N && t % i == 0) {
        ++res;
      }
    }
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  return 0;
}
