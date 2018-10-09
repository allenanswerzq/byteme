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


unordered_map<string, pair<string, string>> mp;

string recu(string start) {
  string dst = mp[start].se;
  if (dst == "") return "";
  string res = start;
  if (dst != "") {
    res += "-" + dst + " " + recu(mp[start].se); 
  }
  return res;
}

string go() {
  string start, end;
  fora (a, mp) {
    string cur = a.fi;
    auto info = a.se;
    // trace(cur, info.fi, info.se);
    if (info.fi == "")
      start = cur;
    if (info.se == "")
      end = cur; 
  }
  // trace(start, end);
  return recu(start);  
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("in.txt", "rt", stdin);
  clock_t begin = clock();
  
  int t; cin >> t;
  fori (i, 0, t) {
    mp.clear(); 
    int n; cin >> n;
    while (n--) {
      string a, b;
      cin >> a; cin >> b;
      // trace(a, b);
      // Parent
      mp[b].fi = a;
      // Child
      mp[a].se = b;
    } 
    string res = go();
    cout << "Case #" << i + 1 << ": " << res << endl;
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
