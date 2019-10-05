//=============================================================
// Name        : 151b
// Date        : Sat Jun 29 18:07:07 CST 2019
// Accepted    : Sat Jun 29 18:33:57 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

struct node {
  int taxi;
  int pizza;
  int girl;
  string name;
};

bool taxi(string s) {
  char c = s[0];
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] != '-' && s[i] != c) {
      return false;
    }
  }
  return true;
}

bool pizza(string s) {
  string a;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] != '-') {
      a += s[i];
    }
  }
  for (int i = 0; i < sz(a) - 1; ++i) {
    if (a[i + 1] >= a[i]) {
      return false;
    }
  }
  return true;
}

void write_out(vector<string> a, string msg) {
  cout << msg;
  for (int i = 0; i < sz(a); ++i) {
    cout << a[i] << (i == sz(a) - 1 ? ".\n" : ", ");
  }
}

void solve() {
  int n;
  cin >> n;
  vector<node> a(n);
  int mt = 0, mp = 0, mg = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    string name;
    cin >> k >> name;
    int t = 0, p = 0;
    for (int j = 0; j < k; ++j) {
      string s;
      cin >> s;
      if (taxi(s)) {
        t++;
      }
      else if (pizza(s)) {
        p++;
      }
    }
    mt = max(mt, t);
    mp = max(mp, p);
    mg = max(mg, k - t - p);
    a[i] = {t, p, k - t - p, name};
  }
  trace(mt, mp, mg, pizza("95-43-21"));
  vector<string> t, p, g;
  for (int i = 0; i < n; ++i) {
    if (a[i].taxi == mt) {
      t.push_back(a[i].name);
    }
    if (a[i].pizza == mp) {
      p.push_back(a[i].name);
    }
    if (a[i].girl == mg) {
      g.push_back(a[i].name);
    }
  }
  write_out(t, "If you want to call a taxi, you should call: ");
  write_out(p, "If you want to order a pizza, you should call: ");
  write_out(g, "If you want to go to a cafe with a wonderful girl, you should call: ");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
