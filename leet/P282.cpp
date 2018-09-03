#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

// Note:
// 1). overflow
// 2). number starts with 0
// 3). multipy problem

#define vs vector<string> 
void dfs(string aa, int goal, ll last, ll sum, string path, vs& res) {
  if (sz(aa) == 0 && sum == goal) {
  res.push_back(path);
  return;
  }

  int n = sz(aa);
  fori (i, 1, n + 1) {
  string cur = aa.substr(0, i);
  if (cur[0] == '0' && sz(cur) > 1) return;
  string nxt = aa.substr(i);
  ll bb = stoll(cur);
  if (sz(path) > 0) {
  dfs(nxt, goal, bb, sum + bb, path + '+' + cur, res);
  dfs(nxt, goal, -bb, sum - bb, path + '-' + cur, res);
  dfs(nxt, goal, last * bb, (sum - last) + last * bb, 
    path + '*' + cur, res);
  } else {
  dfs(nxt, goal, bb, bb, cur, res);
  } 
  }
}

vector<string> addOperators(string aa, int goal) {
  vs res;
  dfs(aa, goal, 0, 0, "", res);
  return res;
}

int main() {
  // vector<string> ret = addOperators("3456237490", 9191);
  vector<string> ret = addOperators("2147483648", -2147483648);
  for (auto s : ret)
  cout << s << "\n";
  return 0;
}
