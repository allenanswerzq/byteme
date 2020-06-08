/* created   : 2020-06-07 18:36:59
 * accepted  : 2020-06-07 20:55:50
 */
#pragma GCC push_options
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

template <int N>
struct HashString {
  using ull = unsigned long long;
  const int base = 131;
  vector<ull> hash;
  vector<ull> hsah; // reverse hash
  vector<ull> mul;
  int n = 0;

  void init() {
    hash.resize(N);
    hsah.resize(N);
    mul.resize(N);
    mul[0] = 1;
    for (int i = 1; i < N; i++) {
      mul[i] = mul[i - 1] * base;
    }
  }

  HashString() { init(); }

  HashString(const string& s) {
    init();
    append(s);
  }

  // Given zero based index, returns the hash value.
  ull get(int l, int r) {
    assert(0 <= l && l <= r && r < n);
    return hash[r + 1] - hash[l] * mul[r - l + 1];
  }

  int reverse_index(int x) {
    assert(0 <= x && x < n);
    return n - x - 1;
  }

  ull get_rev(int l, int r) {
    assert(1 <= l && l <= r);
    int nl = reverse_index(r);
    int nr = reverse_index(l);
    return hsah[nr + 1] - hsah[nl] * mul[r - l + 1];
  }

  void append(const string& s) {
    int l = s.size();
    for (int i = 0; i < l; i++) {
      hash[n + 1 + i] = hash[n + i] * base + s[i] - 'a';
      hsah[n + 1 + i] = hsah[n + i] * base + s[l - i - 1] - 'a';
    }
    n += l;
  }
};

const int N = 3e5 + 7;
HashString<N> hs;
string s;
int n;

bool comp(int x, int y) {
  int lo = 0;
  int hi = min(n - x, n - y) + 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (hs.get(x, x + md - 1) == hs.get(y, y + md - 1)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  // trace(x, y, lo, hi, n, s.substr(x), s.substr(y));
  if (lo == n - x) {
    return true;
  }
  else if (lo == n - y) {
    return false;
  }
  else {
    assert(x + hi - 1 < n);
    assert(y + hi - 1 < n);
    return s[x + hi - 1] < s[y + hi - 1];
  }
}

void solve() {
  cin >> s;
  hs.append(s);
  n = s.size();
  vector<int> sa;
  for (int i = 0; i < n; i++) {
    sa.push_back(i);
  }
  sort(all(sa), comp);
  trace(sa);
  vector<int> ht(n);
  for (int i = 1; i < n; i++) {
    int x = sa[i - 1];
    int y = sa[i];
    int lo = 0;
    int hi = min(n - x, n - y) + 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      trace(md, s.substr(x, md), s.substr(y, md));
      if (hs.get(x, x + md - 1) == hs.get(y, y + md - 1)) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    trace(x, y, lo, hi, s.substr(x), s.substr(y));
    ht[i] = lo;
  }
  trace(ht);
  for (int i = 0; i < n; i++) {
    cout << sa[i] << (i == n - 1 ? '\n' : ' ');
  }
  for (int i = 0; i < n; i++) {
    cout << ht[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
