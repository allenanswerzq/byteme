#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pend cout << endl
#define pvar(x) cout << #x << ": "
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define output(v) cout << (v) << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
#define pvi(x, v) if(v) pvar(x); fora(a, x) cout << a << " "; pend
#define par(x, n, v) if(v) pvar(x); fori(a, 0, n) cout << x[a] << " "; pend

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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int dec(string ss) {
  int ret = 0;
  fori (i, 0, sz(ss)) {
    ret = ret * 26 + (ss[i] - 'A' + 1);
  }
  return ret;
}

string enc(int aa) {
  string ret;
  while (aa) {
    ret = (char)((aa - 1) % 26) + ret;
    aa = (aa - 1) / 26;
  }
  return ret;
}

string solve(string ss) {
  if (sz(ss) == 0) return "";

  string sc, sr;
  bool ok = 0;
  int i = 0;
  while (i < sz(ss) && 'A' <= ss[i] && ss[i] <= 'Z')
    sc += ss[i++];

  while (i < sz(ss) && '0' <= ss[i] && ss[i] <= '9')
    sr += ss[i++];

  if (i == sz(ss)) 
    ok = 1; 

  // trace(sc, sr, ok);
  string ret;
  if (ok) {
    int r = stol(sr);
    int c = dec(sc);
    ret = "R" + to_string(r) + "C" + to_string(c);
  } else {
    char a, b; int r, c;
    istringstream iss(ss);
    iss >> a >> r >> b >> c;
    // trace(a, b, r, c, enc(55), dec("AZ")); 
    ret += enc(c) + to_string(r);
  }
  return ret;
}

int main() {
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    string ss; cin >> ss;
    string ret = solve(ss);
    output(ret);
  }

  return 0;
}

