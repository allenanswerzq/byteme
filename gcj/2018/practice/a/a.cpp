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

vpii bus;
vi goal;

vi go() {
  vi res;
  sort(all(bus));
  fora (g, goal) {
    int cnt = 0;
    fori (i, 0, sz(bus)) {
      auto b = bus[i];
      if (b.fi <= g && g <= b.se) 
        ++cnt;
    }
    res.pb(cnt);
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("in.txt", "rt", stdin);
  clock_t begin = clock();


  int t;
  cin >> t;
  fori(i, 0, t) {

    goal.clear();
    bus.clear();

    int n; cin >> n;
    while (n--) {
      int a, b;
      cin >> a >> b; 
      bus.pb({a, b});
    }

    int k; cin >> k;
    while (k--) {
      int a; cin >> a;
      goal.pb(a); 
    }

    // Main part.
    vi res = go(); 
    cout << "Case #" << i + 1 << ": ";
    fora(r, res)
      cout << r << " ";
    cout << endl;
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed << endl;
  return 0;
}
