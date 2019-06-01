//============================================================================
// Name        : 106a
// Date        : Tue May 28 16:36:15 CST 2019
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
template<class T> void output(T t) { cout << t << "\n"; }
template<class T, class U, class... G>
void output(T t, U u, G... g) { cout << t << " "; output(u, g...); }

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve() {
  char c;
  cin >> c;
  string a, b;
  cin >> a >> b;
  map<char, int> mp;
  mp['6'] = 6;
  mp['7'] = 7;
  mp['8'] = 8;
  mp['9'] = 9;
  mp['T'] = 10;
  mp['J'] = 11;
  mp['Q'] = 12;
  mp['K'] = 13;
  mp['A'] = 14;
  if (a[1] == c && b[1] != c) {
    output("YES");
    return;
  } else if (b[1] == c && a[1] != c) {
    output("NO");
    return;
  } else if (a[1] == b[1]) {
    if (a[1] == b[1]) {
      if (mp[a[0]] > mp[b[0]]) {
        output("YES");
        return;
      }
    }
  }
  output("NO");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
