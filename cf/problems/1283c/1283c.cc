/* created   : 2020-02-05 16:33:09
 * accepted  : 2020-02-05 21:24:10
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

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  vector<int> deg_in(n + 1);
  vector<int> deg_out(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      // i --> a[i]
      deg_in[a[i]]++;
      deg_out[i]++;
    }
  }
  vector<int> need_in;
  vector<int> need_out;
  vector<int> isolated;
  for (int i = 1; i <= n; i++) {
    if (deg_in[i] == 0 && deg_out[i] == 1) {
      need_in.push_back(i);
    }
    else if (deg_in[i] == 1 && deg_out[i] == 0) {
      need_out.push_back(i);
    }
    else if (deg_in[i] == 0 && deg_out[i] == 0) {
      isolated.push_back(i);
    }
    else {
      // do nothing.
    }
  }
  trace(need_in, need_out, deg_in, deg_out);
  if (isolated.empty()) {
    // do nothing.
  }
  if (isolated.size() == 1) {
    assert(!need_in.empty());
    a[isolated[0]] = need_in.back();
    need_in.pop_back();
    need_in.push_back(isolated[0]);
  }
  else if (isolated.size() > 1) {
    int in = isolated[0];
    int out = in;
    for (int i = 1; i < isolated.size(); i++) {
      a[isolated[i]] = in;
      in = isolated[i];
    }
    need_in.push_back(in);
    need_out.push_back(out);
  }
  assert(need_in.size() == need_out.size());
  trace(need_in, need_out, a);
  for (int i = 0; i < need_in.size(); i++) {
    a[need_out[i]] = need_in[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
