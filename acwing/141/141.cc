/* created   : 2020-06-07 10:00:38
 * accepted  : 2020-06-07 18:02:05
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
  vector<ull> hash_rev; // reverse hash
  vector<ull> mul;
  int n;

  void init() {
    hash.resize(N);
    hash_rev.resize(N);
    mul.resize(N);
    mul[0] = 1;
    for (int i = 1; i < N; i++) {
      mul[i] = mul[i - 1] * base;
    }
    hash[0] = 0;
    hash_rev[0] = 0;
  }

  HashString(const char* s, int len) {
    n = len;
    init();
    append(s);
  }

  ull get(int l, int r) {
    assert(1 <= l && l <= r);
    return hash[r] - hash[l - 1] * mul[r - l + 1];
  }

  int reverse_index(int x) {
    return n - x + 1;
  }

  ull get_rev(int l, int r) {
    assert(1 <= l && l <= r);
    int nl = reverse_index(r);
    int nr = reverse_index(l);
    return hash_rev[nr] - hash_rev[nl - 1] * mul[r - l + 1];
  }

  void append(const char* s) {
    for (int i = 1, j = n; i <= n; i++, j--) {
      hash[i] = hash[i - 1] * base + s[i] - 'a';
      hash_rev[i] = hash_rev[i - 1] * base + s[j] - 'a';
    }
  }
};

const int N = 2e6 + 7;
char a[N];

void solve() {
  int n = strlen(a + 1);
  for (int i = 2 * n; i > 0; i -= 2) {
    a[i] = a[i / 2];
    a[i - 1] = '#';
  }
  n *= 2;
  HashString<N> hs(a, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int lo = 0;
    int hi = min(i - 1, n - i) + 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      if (hs.get(i - md, i - 1) == hs.get_rev(i + 1, i + md)) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    ans = max(ans, (a[i - lo] == '#' ? lo : lo + 1));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (scanf("%s", a + 1) && string(a + 1) != "END") {
    cout << "Case " << tc++ << ": ";
    solve();
  }
  return 0;
}
