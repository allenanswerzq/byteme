#include<bits/stdc++.h>
using namespace std;

// TODO: Only pass the small data.

int mx;
void dfs(vi inp, int honor, int energy, int steps) {
  if (honor < 0) return;
  if (energy < 1) return;
  if (steps == 0) {
    mx = max(mx, honor);
    return;
  }

  fori (i, 0, steps) {
    vi delay = inp;
    int x = delay[0];
    delay.erase(delay.begin());
    delay.insert(delay.end(), x); 

    // pvi(delay);
    // trace(honor, energy, steps, mx);

    // Dance.
    vi tmp = delay;
    int v = tmp[0];
    energy -= v;
    tmp.erase(tmp.begin());
    dfs(tmp, honor + 1, energy, steps - 1);
    energy += v;

    // Truce.
    tmp = delay;
    tmp.erase(tmp.begin());
    dfs(tmp, honor, energy, steps - 1);

    // Recruit.
    tmp = delay;
    x = tmp[0];
    energy += x;
    tmp.erase(tmp.begin());
    dfs(tmp, honor - 1, energy, steps - 1);
    energy -= x;

    // Note: very important code here.
    inp = delay;
  }

}

int main() {
   
  int t; cin >> t;
  fori (i, 1, t + 1) {
    int e, n; cin >> e >> n;
    vi inp;
    mx = 0;
    fori (j, 0, n) {
      int k; cin >> k;
      inp.pb(k);
    }
    // trace(e, n);
    dfs(inp, 0, e, n);
    output(i, mx);
  }

  return 0;
}
