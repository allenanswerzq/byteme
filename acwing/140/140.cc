/* created   : 2020-06-07 07:35:53
 * accepted  : 2020-06-07 09:44:32
 */
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
  vector<ull> mul;
  int k = 0;

  HashString(const string& s) {
    hash.resize(N);
    mul.resize(N);
    mul[0] = 1;
    for (int i = 1; i < N; i++) {
      mul[i] = mul[i - 1] * base;
    }
    hash[k++] = 0;
    append(s);
  }

  ull get(int l, int r) {
    return dbg(hash[r] - hash[l - 1] * mul[r - l + 1]);
  }

  void append(const string& s) {
    for (auto ch : s) {
      hash[k] = hash[k - 1] * base;
      hash[k++] += ch - 'a' + 1;
    }
  }
};

void solve() {
  string s; cin >> s;
  HashString<(int)1e6 + 7> hs(s);
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (hs.get(l1, r1) == hs.get(l2, r2)) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
//
