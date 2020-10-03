/* created   : 2020-10-03 09:40:09
 * accepted  : 2020-10-03 10:43:21
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
  string shortestPalindromeBinarySearch(string S) {
    string T;
    for (int i = 0; i < S.size(); i++) {
      if (i > 0) T += '#';
      T += S[i];
    }
    int n = T.size();
    HashString<(int) 1e5> hs(T);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
      // 0...i....
      int lo = -1;
      int hi = min(i, n - i - 1) + 1;
      while (lo + 1 < hi) {
        int md = (lo + hi) >> 1;
        if (hs.get(i - md, i) == hs.get_rev(i, i + md)) {
          lo = md;
        }
        else {
          hi = md;
        }
      }
      f[i] = lo;
    }
    // ___p___xx
    int p = 0;
    for (int i = 1; i < n; i++) {
      if (f[i] > f[p] && i - f[i] == 0) {
        p = i;
      }
    }
    trace(T, p, f);
    int t = p + f[p];
    assert(t + 1 <= n);
    string c = T.substr(t + 1);
    reverse(c.begin(), c.end());
    c.append(T);
    string ans;
    for (char h : c) {
      if (h != '#') ans.push_back(h);
    }
    trace(ans);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

string test(string S) {
  Solution sol;
  return sol.shortestPalindrome(S);
}

void solve() {
  EXPECT(test("aacecaaa"), "aaacecaaa");
  EXPECT(test("dbab"), "babdbab");
  EXPECT(test("aad"), "daad");
  EXPECT(test("abcd"), "dcbabcd");
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
