/* created   : 2020-12-30 22:46:09
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct H {
  using ull = unsigned long long;
  ull x = 0;

  H() {}

  H(ull x_) : x(x_) {}

  H operator+(H o) {
    ull r = x;
    asm("addq %%rdx, %0\n"
        "adcq $0,%0\n"
        : "+a"(r)    // %0, output operand
        : "d"(o.x)); // %1, input operand
    return r;
  }

  H operator*(H o) {
    // eax = r
    // mul o.x eax -> eax
    // add rdx eax ->
    ull r = x;
    asm("mul %1\n"
        "addq %%rdx, %0\n"
        "adcq $0,%0\n"
        : "+a"(r)
        : "r"(o.x)
        : "rdx");
    return r;
  }

  H operator-(H o) { return *this + ~o.x; }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};

struct HashString {
  const H C = (ll)1e11 + 3;  // (order ~ 3e9; random also ok)

  vector<H> ha, pw;

  HashString(string& str) {
    int n = str.size();
    ha.resize(n + 1);
    pw.resize(n + 1);
    pw[0] = 1;
    for (int i = 0; i < n; i++) {
      ha[i + 1] = ha[i] * C + str[i];
      pw[i + 1] = pw[i] * C;
    }
  }

  // Compute the hash for interval [a, b)
  H hash(int a, int b) {
    return ha[b] - ha[a] * pw[b - a];
  }
};

void solve() {
  string S; cin >> S;
  HashString hs(S);
  int n = S.size();
  vector<int> ans;
  for (int len = 1; len <= n; len++) {
    auto h = hs.hash(0, len);
    bool ok = true;
    for (int j = len; j < n && ok; j += len) {
      if (j + len - 1 < n) {
        ok &= (h == hs.hash(j, j + len));
      } else {
        ok &= (hs.hash(0, n - j) == hs.hash(j, n));
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
