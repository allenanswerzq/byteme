/* created   : 2020-04-19 07:36:34
 * accepted  : 2020-04-19 11:01:19
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int mod = 1e9;

struct Node {
  ll dx;
  ll dy;
  int end;
};

Node rec(int lo, string& s) {
  trace("dfs", s.substr(lo));
  assert(isdigit(s[lo]));
  int p = -1;
  for (int i = lo; i < (int) s.size(); i++) {
    if (s[i] == '(') {
      p = i;
      break;
    }
  }
  assert(p != -1);
  ll cnt = stol(s.substr(lo, p - lo));
  trace(p, cnt);
  ll dx = 0;
  ll dy = 0;
  vector<Node> ans;
  int i = p + 1;
  for (; i < (int) s.size(); i++) {
    if (s[i] == 'N') {
      dx--;
    }
    else if (s[i] == 'S') {
      dx++;
    }
    else if (s[i] == 'E') {
      dy++;
    }
    else if (s[i] == 'W') {
      dy--;
    }
    else if (isdigit(s[i])) {
      auto rest = rec(i, s);
      // ( () wwwee ())
      ans.push_back(rest);
      i = rest.end;
    }
    else if (s[i] == ')') {
      break;
    }
    else {
      trace(i, s[i]);
      assert(false);
    }
  }
  for (auto node : ans) {
    dx += node.dx;
    dx %= mod;
    dy += node.dy;
    dy %= mod;
  }
  return {cnt * dx % mod, cnt * dy % mod, i};
}

void solve() {
  string s; cin >> s;
  s = "1(" + s;
  s += ")";
  int n = s.size();
  auto p = rec(0, s);
  trace(p.dx, p.dy, p.end, n);
  int x = (p.dx + mod) % mod + 1;
  int y = (p.dy + mod) % mod + 1;
  cout << y << ' ' << x << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
