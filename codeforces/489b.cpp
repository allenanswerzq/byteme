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


int main(int argc, char** argv) {
  int n, m; cin >> n;
  vi aa, bb;
  fori (i, 0, n) {
    int a; cin >> a;
    aa.pb(a);
  }
  cin >> m;
  fori (i, 0, m) {
    int a; cin >> a;
    bb.pb(a);
  }

  sort(all(aa));
  sort(all(bb));
  
  int ret = 0;
  vi visit(m, 0);
  fori (i, 0, sz(aa)) {
    fori (j, 0, sz(bb)) {
      if (visit[j]) continue;
      if (abs(bb[j] - aa[i]) <= 1) {
        ++ret;
        visit[j] = 1;
        break;
      }
    }
  }
  output(ret);

  return 0;
}
