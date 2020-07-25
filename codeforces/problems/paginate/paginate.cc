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

vector<string> split(string s) {
  vector<string> ret;
  int n = s.size();
  int last = 0;
  for (int i = 0; i <= n; i++) {
    if (i == n || s[i] == ',') {
      ret.push_back(s.substr(last, i - last));
      last = i + 1;
    }
  }
  return ret;
}

void solve() {
}

int main() {
  solve();
}
