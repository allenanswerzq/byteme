//============================================================================
// Name        : 1051a
// Date        : Sun Apr 21 19:31:54 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

bool ok(string s) {
  vi a(3);
  for (int i = 0; i < sz(s); ++i) {
    if (isupper(s[i])) {
      a[0] = 1;
    } else if (islower(s[i])) {
      a[1] = 1;
    } else if (isdigit(s[i])) {
      a[2] = 1;
    }
  }
  return a[0] && a[1] && a[2];
}

bool same(char a, char b) {
  bool c = isupper(a) && isupper(b);
  bool d = islower(a) && islower(b);
  bool e = isdigit(a) && isdigit(b);
  return c || d || e;
}

void solve() {
  string s;
  cin >> s;
  if (ok(s)) {
    cout << s << "\n";
    return;
  }
  vector<char> ch = {'0', 'a', 'A'};
  for (int i = 0; i < sz(s); ++i) {
    for (int j = 0; j < 3; ++j) {
      string t = s;
      t[i] = ch[j];
      if (ok(t)) {
        cout << t << "\n";
        return;
      }
    }
  }
  trace(s);
  for (int j = 0; j < 3; ++j) {
    if (same(s[2], ch[j])) {
      string sub;
      for (int k = 0; k < 3; ++k) {
        if (k != j) {
          sub += ch[k];
        }
      }
      s[0] = sub[0], s[1] = sub[1];
    }
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
