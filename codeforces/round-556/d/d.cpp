//============================================================================
// Name        : d
// Date        : Tue Apr 30 00:00:05 CST 2019
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

bool check(vector<string>& r, vi& a) {
  vi b(26);
  for (int i = 1; i < 4; ++i) {
    for (auto ch : r[i]) {
      b[ch - 'a']++;
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (b[i] > a[i]) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vi a(26);
  for (int i = 0; i < n; ++i) {
    a[s[i] - 'a']++;
  }
  // trace(a);
  vector<string> r(4);
  for (int i = 0; i < q; ++i) {
    char op;
    int who;
    char ch;
    cin >> op;
    if (op == '+') {
      cin >> who >> ch;
      r[who] += ch;
    } else {
      cin >> who;
      r[who].pop_back();
    }
    trace(r);
    if (check(r, a)) {
      output("YES");
    } else {
      output("NO");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

