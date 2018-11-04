#include<bits/stdc++.h>
using namespace std;

vvi bus;
int city;
int cost;
int finish;

ll next(int cur, int s, int f, int d) { 
  int x = 0;
  while (s + x * f < cur) ++x;
  return (s + x * f + d);
}

umap<string, int> dp;

ll solve(int ix, ll start, ll finish, ll path) {
  // trace(city, ix, start, finish, path);
  if (start > finish) return -1;
  if (ix == city - 1 && start <= finish) {
    return path;
  }

  string state = to_string(ix) + to_string(start) + 
                 to_string(finish) + to_string(path);
                 
  if (dp[state]) 
    return dp[state];

  // Go to see this city.
  ll cur = start + cost;
  ll nxt = next(cur, bus[ix][0], bus[ix][1], bus[ix][2]);
  ll r1 = solve(ix + 1, nxt, finish, path + 1);

  // Do not see this city;
  cur = start;
  nxt = next(cur, bus[ix][0], bus[ix][1], bus[ix][2]);
  ll r2 = solve(ix + 1, nxt, finish, path);

  dp[state] = max(r1, r2);

  return max(r1, r2);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    bus.clear();
    dp.clear();
    cin >> city >> cost >> finish;
    fori (i, 0, city - 1) {
      int a, b, c; cin >> a >> b >> c;
      vi tmp; tmp.pb(a); tmp.pb(b); tmp.pb(c);
      bus.pb(tmp);
    }
    ll r = solve(0, 0, finish, 0);
    if (r == -1) 
      output(i, "IMPOSSIBLE");
    else 
      output(i, r);
  }

  return 0;
}
