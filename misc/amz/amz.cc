/* created   : 2022-05-01 00:23:15
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

// Compute the total characters that are unique in all substrings for a string.
int brute_force(const string & S) {
  int n = S.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string sub = S.substr(i, j - i + 1);
      set<char> st(all(sub));
      ans += st.size();
    }
  }
  return ans;
}

int contri(const string & S) {
  vector<int> cnt(26, -1);
  int n = S.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int c = S[i] - 'a';
    int l = (i - cnt[c] - 1);
    int r = (n - i - 1);
    // ans += l * r + l + r + 1;
    ans += (l + 1) * (r + 1);
    cnt[c] = i;
  }
  return ans;
}

void test(const string & s) {
  assert(brute_force(s) == contri(s));
}

void solve() {
  test("good");
  test("test");
  test("goaobod");
  test("abacabadabacaba");
}

int main() {
  solve();
  return 0;
}
