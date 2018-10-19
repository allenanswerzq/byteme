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

// TODO
class Disjoint {
private:
  vector<int> e, rank, ssize_;
  int size_;

public:
  Disjoint(int n) {
    size_ = n;
    rank.assign(n, 0);
    e.assign(n, 0);
    for (int i = 0; i < n; i++) e[i] = i;
    ssize_.assign(n, 1);
  }
  
  int find(int i) {
    return (e[i] == i) ? i : e[i] = find(e[i]);
  }

  bool same(int i, int j) {
    return find(i) == find(j);
  }

  void joint(int i, int j) {
    if (!same(i, j)) {
      int x = find(i), y = find(j);
      if (rank[x] > rank[y]) {
        ssize_[find(x)] += ssize_[find(y)]; e[y] = x;
      } else {
        ssize_[find(y)] += ssize_[find(x)]; e[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
      size_--;
    }
  }

  // Returns the size_ of a specific set.
  int ssize(int i) {
    return ssize_[find(i)];
  }

  // Returns the size_ of the whole disjont set.
  int size() {
    return size_;
  }
};

const int maxn = 1e3 + 7;
int n, x, y;
pii aa[maxn];

bool check(int a, int b) {
  int x1 = aa[a].first, y1 = aa[a].second;
  int x2 = aa[b].first, y2 = aa[b].second;

  // trace(x1, y1, x2, y2, x, y);
  if ((y1 - y) * (x2 - x) == (y2 - y) * (x1 - x)) {
    return 1;
  }
  return 0;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;

  cin >> n >> x >> y;
  fori (i, 0, n) {
    int a, b; cin >> a >> b;
    aa[i].first = a;
    aa[i].second = b;
  }

  Disjoint djs(n);
  fori (i, 0, n) {
    fori (j, 0, n) {
      if (j == i) continue;
      if (check(i, j)) {
        djs.joint(i, j);
      } 
    }
  }

  output(sz(djs));
  return 0;
}

