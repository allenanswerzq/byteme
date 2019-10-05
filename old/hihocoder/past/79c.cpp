#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << '\n'
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << '\n'
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << '\n';
}

template <typename T, typename... Args>
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ',');
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...);
}

double tick() {
  static clock_t old;
  clock_t now = clock();
  double diff = 1.0 * (now - old);
  diff /= CLOCKS_PER_SEC;
  old = now;
  return diff;
}

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

ll square(int x) {
  return 1ll * x * x;
}

void solve() {
  int n, m;
  cin >> n >> m;
  set<int> st;
  fori (i, 0, n ) {
    int x; cin >> x;
    st.insert(x);
  }

  ll sum = 0;
  int p = -1;
  fora (a, st) {
    if (p != -1) 
      sum += square(a - p);
    p = a;
  }

  auto it = st.begin();
  while (m--) {
    string op; int x; cin >> op >> x;
    if (op == "INS") {
      it = st.lower_bound(x);
      if (it == st.end()) {
        // a end
        // a x end
        if (sz(st)) sum += square(x - *(--it));
      } else if (*it != x) {
        // a v
        // a x v
        int v = *it;
        sum += square(v - x);
        if (it != st.begin()) 
          sum += square(x - *(--it)) - square(v - *it);
      }
      st.insert(x);

    } else {
      it = st.lower_bound(x);
      if (it != st.end() && *it == x) {
        auto hi = it; hi++;
        int r = -1,l = -1;
        if (hi != st.end()) {
          sum -= square(*hi - x);
          r = *hi;
        }

        if (it != st.begin()) {
          sum -= square(x - *(--it));
          l = *it;
        }

        if (l != -1 && r != -1)
          sum += square(r - l);
        st.erase(x);
      }
    }

    output(sum);
  }
}

int main() {
  solve();
}
