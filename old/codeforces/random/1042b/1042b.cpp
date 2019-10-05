//============================================================================
// Name        : 1042b
// Date        : Fri Apr 26 21:29:34 CST 2019
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
  int n;
  cin >> n;
  map<string, int> mp;
  map<char, int> sg;
  for (int i = 0; i < n; ++i) {
    int p;
    string v;
    cin >> p >> v;
    sort(all(v));
    if (mp.count(v)) {
      mp[v] = min(mp[v], p);
    } else {
      mp[v] = p;
    }
    for (auto c : v) {
      if (sg.count(c)) {
        sg[c] = min(sg[c], p);
      } else {
        sg[c] = p;
      }
    }
  }
  string vit = "ABC";
  for (auto c : vit) {
    if (!sg.count(c)) {
      output(-1);
      return;
    }
  }
  // ab ac bc abc a b c
  function<ll(string)> get = [&](string a) {
    if (mp.count(a)) {
      return mp[a];
    } else {
      return (1 << 30);
    }
  };
  ll ret = get("A") + get("B") + get("C");
  ret = min(ret, get("ABC"));
  ret = min(ret, get("AB") + get("C"));
  ret = min(ret, get("AC") + get("B"));
  ret = min(ret, get("BC") + get("A"));
  ret = min(ret, get("AB") + get("BC"));
  ret = min(ret, get("AC") + get("AB"));
  ret = min(ret, get("BC") + get("AC"));
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
