#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>
#include <cassert>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define sz(a) int((a).size())
#define rep(i, s, n)  for(int i = s; i <= (n); ++i)
#define rev(i, n, s)  for(int i = (n); i >= s; --i)
#define fore(x, a) for(auto &&x : a)
typedef long long ll;
const int mod = 1000000007;
const int N = 105;

struct Comp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second > p2.second;
  }
};

int main() {
#ifdef loc
  if(!freopen((string(VSFOLDER) + "in.txt").c_str(), "r", stdin)) {
    assert(0);
  }
  freopen((string(VSFOLDER) + "out.txt").c_str(), "w", stdout);
#endif
  boost;
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  rep(i, 0, n - 1) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end(), Comp());
  int mx = -2147483647;
  int ans = 0;
  rep(i, 0, n - 1) {
    if (a[i].second <= mx || (i+1<n && a[i] == a[i+1])) {
      ans++;
    }
    mx = max(mx, a[i].second);
  }
  cout << ans << endl;
  return 0;
}
