#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
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
  cout << fixed << name << ": " << arg << '\n';
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

string finall(32, 1), space(32, 1);

void get_space() {
  fori (i, 0, 4) fori (j, 1, 8) {
    int x; cin >> x;
    if (x % 10 == 1) {
      space[(x / 10 - 1) * 8] = x;
      space[i * 8 + j] = 1;
    } else {
      space[i * 8 + j] = x;
    }
  }
}


void step(string& inp, char ng, int tdx) {
  int idx = 0;
  while (idx < 32 && inp[idx] != ng) {
    ++idx;
  }

  if (idx != 32) {
    inp[tdx] = ng;
    inp[idx] = 1;
  }
}

void bfs() {
  deque<string> dq;
  unordered_set<string> visit;

  dq.pb(space);
  visit.insert(space);


  int level = 0;
  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      string cur = dq.front(); dq.pop_front();
      if (cur == finall) {
        output(level);
        return;
      }

      fori (k, 0, 4) {
        fori (j, 1, 8) {
          int gp = cur[k * 8 + j];
          int ng = cur[k * 8 + j - 1];
          if (gp == 1 && ng != 1) {
            string nxt = cur;
            step(nxt, ng + 1, k * 8 + j);
            if (!visit.count(nxt)) {
              visit.insert(nxt);
              dq.pb(nxt);
            }
          }
        }
      }
    }
    ++level;
  }

  output(-1);
}

void solve() {
  get_space();
  bfs();
}

int main() {
  fori (i, 0, 4) {
    fori (j, 0, 7) {
      finall[i * 8 + j] = (i + 1) * 10 + j + 1;
    }
  }

  int t; cin >> t >> ws;
  fori (i, 0, t) {
    solve();
  }

  // while (1);
  return 0;
}

