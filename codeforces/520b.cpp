#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(val) cout << (val) << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl
#define pvi(x) cout << #x << ": "; fora(a, x) cout << a << " "; cout << endl
#define par(x, n) cout<< #x << ": "; fori(a, 0, n) cout<<x[a]<<" "; cout <<endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


// TODO
int main(int argc, char** argv) {
  int n, m; cin >> n >> m;
  unordered_set<int> visit;
  deque<int> dq;
  dq.pb(n);
  int ret = 0;
  bool ok = 0;
  while (sz(dq)) {
    int kk = sz(dq);
    fori (i, 0, kk) {
      auto top = dq.front(); dq.pop_front();
      if (visit.count(top)) continue;
      visit.insert(top);
      if (top == m) {ok = 1; break;}
      if (top - 1 > 0) dq.pb(top - 1);
      if (2 * top < m + 11) dq.pb(top * 2); 
    }
    if (ok) break;
    ++ret;
  }
  output(ret);


  return 0;
}
