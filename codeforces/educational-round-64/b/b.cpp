//============================================================================
// Name        : b
// Date        : Wed May  1 22:47:09 CST 2019
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
template<typename T> void output(T t) { cout << t << "\n"; }
template<typename T, typename U, typename... Args>
void output(T t, U u, Args... args) { cout << t << " "; output(u, args...); }

#ifndef _has_trace
#define trace(...)
#define dbstream ostream
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

void solve() {
  string s;
  cin >> s;
  vi a(26);
  for (int i = 0; i < sz(s); ++i) {
    a[s[i] - 'a']++;
  }
  vi c = a;
  int cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (a[i] > 0) {
      cnt++;
    }
  }
  string ret;
  if (cnt == 1) {
    for (int i = 0; i < 26; ++i) {
      if (a[i] > 0) {
        while (a[i]-- > 0) {
          ret += (char)('a' + i);
        }
        output(ret);
        return;
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = i + 2; j < 26 && a[i] > 0; ++j) {
      if (a[j] == 0) {
        continue;
      }
      int x = a[j] >= a[i] ? a[i] : a[j];
      int t = x;
      while (t-- > 0) {
        ret += (char)('a' + j);
      }
      t = x;
      while (t-- > 0) {
        ret += (char)('a' + i);
      }
      a[i] -= x;
      a[j] -= x;
    }
    if (a[i] > 0) {
      output("No answer");
      return;
    }
  }
  vi b(26);
  for (int i = 0; i < sz(ret); ++i) {
    b[ret[i] - 'a']++;
  }
  assert(b == c);
  assert(sz(ret) == sz(s));
  for (int i = 0; i < sz(ret); ++i) {
    if (i + 1 < sz(ret) && abs(ret[i] - ret[i + 1]) == 1) {
      assert(false);
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}

