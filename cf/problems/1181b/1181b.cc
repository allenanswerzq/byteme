/* created   : 2020-02-17 20:34:47
 * accepted  : 2020-02-17 21:38:10
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

string add(string& a, string& b) {
  if (a.size() < b.size()) {
    swap(a, b);
  }
  reverse(all(a));
  reverse(all(b));
  int carry = 0;
  string ans;
  for (int i = 0; i < a.size(); i++) {
    int cur = 0;
    cur += (a[i] - '0');
    cur += carry;
    if (i < b.size()) {
      cur += (b[i] - '0');
    }
    ans.push_back((char) (cur % 10 + '0'));
    carry = cur / 10;
  }
  if (carry > 0) {
    ans.push_back('1');
  }
  reverse(all(ans));
  return ans;
}

bool compare(string& a, string& b) {
  int na = a.size();
  int nb = b.size();
  if (na != nb) {
    return na < nb;
  }
  else {
    return a < b;
  }
}

string get(string& s, int p) {
  string a;
  for (int i = 0; i < p; i++) {
    a += s[i];
  }
  string b;
  for (int i = p; i < s.size(); i++) {
    b += s[i];
  }
  trace(p, a, b);
  return add(a, b);
}

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  // ----000000----
  vector<int> b_start;
  int k = 0;
  for (int i = n / 2; i < n && k < 3; i++) {
    if (s[i] != '0') {
      b_start.push_back(i);
      k++;
    }
  }
  k = 0;
  for (int i = n / 2; i >= 1 && k < 3; i--) {
    if (s[i] != '0') {
      b_start.push_back(i);
      k++;
    }
  }
  vector<string> v;
  for (auto p : b_start) {
    v.push_back(get(s, p));
  }
  trace(v);
  sort(all(v), compare);
  cout << v[0] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
