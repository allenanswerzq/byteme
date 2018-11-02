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
#define outret(v) cout << (v) << '\n'
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << '\n'
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
  static clock_t oldtick;
  clock_t newtick = clock();
  double diff = 1.0 * (newtick - oldtick) / CLOCKS_PER_SEC;
  oldtick = newtick;
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

typedef struct Node{
  int sum;
  int id;
  bool operator < (const Node &b) const {
    if (sum != b.sum)
      return sum > b.sum; 
    return id < b.id;
  } 
} Node;

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  Node aa[n];
  fori (i, 0, n) {
    int a, b, c, d; 
    cin >> a >> b >> c >> d;
    aa[i].sum = a + b + c + d;
    aa[i].id = i;
  }

  sort(aa, aa + n);

  // fori (i, 0, n) {
  //   trace(aa[i].sum, aa[i].id);
  // }

  int ret = -1;
  fori (i, 0, n) {
    if (aa[i].id == 0) {
      ret = i + 1;
    }
  } 

  outret(ret); 
  return 0;
}

