/* created   : 2020-09-25 18:42:26
 * accepted  : 2020-09-25 19:20:17
 */
#include <bits/stdc++.h>
using namespace std;
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

class Solution {
 public:
  bool check(const string& s) {
    int lo = 0;
    int hi = s.size() - 1;
    while (lo < hi) {
      if (s[lo++] != s[hi--]) return false;
    }
    return true;
  }

  int minCutDfs(string S) {
    if (check(S)) return 0;
    int n = S.size();
    int ans = 1e9;
    for (int len = 1; len <= n - 1; len++) {
      ans = min(ans, minCutDfs(S.substr(0, len)) + 1 + minCutDfs(S.substr(len)));
    }
    return ans;
  }

  int minCutDP(string S) {
    int n = S.size();
    // trace(n);
    HashString<(int) 1e4> hs(S);
    const int INF = 1e9;
    vector<vector<int>> f(n, vector<int>(n, INF));
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int j = i + len - 1;
        if (hs.get(i, j) == hs.get_rev(i, j)) {
          f[i][j] = 0;
        }
        else {
          for (int k = i; k < j; k++) {
            f[i][j] = min(f[i][j], f[i][k] + 1 + f[k + 1][j]);
          }
        }
        // trace(i, j, f[i][j]);
      }
    }
    // trace(f);
    return f[0][n - 1];
  }

  int minCut(string S) {
    return minCutDfs(S);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& S) {
  Solution sol;
  return sol.minCut(S);
}

void solve() {
  EXPECT(test("aab"), 1);
  EXPECT(test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
