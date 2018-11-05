#include <bits/stdc++.h>
using namespace std;

vi quiet;
unordered_map<int, vi> mp;
int cache[520];

int dfs(int x) {
  // If we can not make sure which person has more money.
  if (!mp.count(x)) return x;
  if (cache[x]) return cache[x];

  vi g = mp[x];
  int least = quiet[x];
  int least_idx = x;

  fori(i, 0, sz(g)) {
    int t = dfs(g[i]);
    cache[g[i]] = t;
    if (quiet[t] < least) {
      least = quiet[t];
      least_idx = t;
    }
  }
  return least_idx;
}

class Solution {
public:
  vector<int> loudAndRich(vvi& richer, vi& q) {
    quiet = q;
    int n = sz(q);
    mp.clear();
    mst(cache, 0);

    fora (v, richer) {
      int lo = v[1], hi = v[0];
      mp[lo].pb(hi);
    }

    fora(it, mp) {
      vi g = it.se;
      cout << it.fi << ": ";
      pvi(g);
    }

    vi res;
    fori(i, 0, sz(q)) {
      int r;
      if (cache[i] > 0) r = cache[i];
      else r = dfs(i);
      res.pb(r);
    }
    return res;
  }
};

int main() {
  return 0;
}
