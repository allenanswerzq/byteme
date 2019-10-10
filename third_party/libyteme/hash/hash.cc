/* created   : 2019-10-10 00:36:05
 * accepted  : 2019-10-10 00:39:57
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

// https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values
size_t hash_combine(const size_t& a, const size_t& b) {
  return a ^ (b + 0x9e3779b9 + (a << 6) + (a >> 2) );
}

namespace std {
template <>
struct hash<vector<int>> {
  size_t operator()(const vector<int>& v) const {
  size_t seed = v.size();
    for (auto x : v) {
      seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
}

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
