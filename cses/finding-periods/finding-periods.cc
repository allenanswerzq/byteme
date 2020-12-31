/* created   : 2020-12-30 22:46:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <int N>
struct HashString {
  using ull = unsigned long long;
  const int base = 131;
  vector<ull> hash;
  vector<ull> hsah;  // reverse hash
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
    assert(0 <= l && l <= r);
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

void solve() {
  string S; cin >> S;
  HashString<(int)1e6 + 7> hs(S);
  int n = S.size();
  vector<int> ans;
  for (int len = 1; len <= n; len++) {
    auto h = hs.get(0, len - 1);
    bool ok = true;
    for (int j = len; j < n && ok; j += len) {
      if (j + len - 1 < n) {
        ok &= (h == hs.get(j, j + len - 1));
      }
      else {
        ok &= (hs.get(0, n - j - 1) == hs.get(j, n - 1));
      }
    }
    if (ok) {
      ans.push_back(len);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
