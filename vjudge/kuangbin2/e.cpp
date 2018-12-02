// #include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <iostream>
#include <cstring>
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

// double tick() {
//   static clock_t old;
//   clock_t now = clock();
//   double diff = 1.0 * (now - old);
//   diff /= CLOCKS_PER_SEC;
//   old = now;
//   return diff;
// }

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


const int maxn = 2015538 + 2000;
int n, cnt, shift, finall, visit[maxn];
string gene = "ACGT";
vs seq;

void bfs() {
  deque<int> dq;
  int pos[10];
  // All cursors point to 0 first.
  dq.pb(0);
  int level = 0;
  while (sz(dq)) {
    int l = sz(dq);
    fori (i, 0, l) {
      int cur = dq.front(); dq.pop_front();

      if (cur == finall) {
        output(level);
        return;
      }

      // Compute the cursor for each sequence.
      fori (i, 0, n) {
        pos[i] = cur % shift;
        cur /= shift;
      }

      // par(pos, n, 1);

      fori (j, 0, 4) {
        // Update the cursor for each sequence according to
        // the last gene symbol `gene[j]` we added.
        int nxt = 0;
        // Two choices here: if new added gene matches, forward cursor by 1.
        // Otherwise keep the old cursor and wait for the later update.
        // See e.jpeg for a strightforwd explanation.
        ford (i, n - 1, -1) {
          nxt = nxt * shift + pos[i] + (seq[i][pos[i]] == gene[j]);
        }

        if (visit[nxt] != cnt) {
          visit[nxt] = cnt;
          dq.pb(nxt);
        }
      }
    }
    ++level;
  }
}

void solve() {
  cin >> n;
  seq.clear();
  // mst(visit, 0);
  shift = 0;
  fori (i, 0, n) {
    string s; cin >> s;
    seq.pb(s);
    shift = max(sz(s), shift);
  }

  ++shift;
  finall = 0;
  ford (i, n - 1, -1) {
    finall = finall * shift + sz(seq[i]);
  }
  // An optimization so that we dont need to call memset for every case.
  ++cnt;
  // trace(finall, shift);
  bfs();
}


int dfs(int depth, vi &pos, int &deep) {
  // trace(depth, deep);
  // pvi(pos, 1);
  if (depth >= deep) {
    return -1;
  }

  int diff = 0;
  fori (i, 0, n) {
    int tmp = sz(seq[i]) - pos[i];
    diff = max(diff, tmp);
  }

  if (diff == 0) {
    return depth;
  }


  if (depth + diff >= deep) {
    return -1;
  }

  fori (i, 0, 4) {
    vi npos = pos;
    int ok = 0;
    fori (j, 0, n) {
      if (seq[j][pos[j]] == gene[i]) {
        npos[j] += 1;
        ok = 1;
      }
    }

    if (ok) {
      int ret = dfs(depth + 1, npos, deep);
      if (ret != -1) {
        return ret;
      }
    }
  }

  return -1;
}

void solve2() {
  cin >> n;
  seq.clear();
  // mst(visit, 0);
  int deep = 0;
  fori (i, 0, n) {
    string s; cin >> s;
    seq.pb(s);
    deep = max(sz(s), shift);
  }

  vi pos(n, 0);
  while (1) {
    int level = dfs(0, pos, deep);
    if (level != -1) {
      output(level);
      return;
    } else {
      ++deep;
    }
  }
}

int main() {
  int t; cin >> t >> ws;
  cnt = 0;
  fori (i, 1, t + 1) {
    // solve();
    solve2();
  }
  return 0;
}

