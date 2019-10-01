#include <bits/stdc++.h>
using namespace std;

namespace kmp_t {
template <typename T>
vector<int> create_table(const T &s) {
  int n = s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

template <typename T>
vector<int> search(const T &s, const T &w, const vector<int> &p) {
// returns 0-indexed positions of occurrences of s in w
  int n = s.size();
  int m = w.size();
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
}

template <typename T>
vector<int> search(const T &s, const T &w) {
  vector<int> p = create_table(s);
  return search(s, w, p);
}
} // namespace kmp_t

void test() {
  string str = "abcd abcd ef abcd";
  // Pattern that needs to be matched.
  string pat = "abcd";
  auto v = kmp_t::search<string>(pat, str);
  trace(pat, str, v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  test();
  return 0;
}

