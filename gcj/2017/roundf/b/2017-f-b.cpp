#include<bits/stdc++.h>
using namespace std;




template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-f-b-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();
  
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


  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
