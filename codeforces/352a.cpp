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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  int a, b;
  a = b = 0;
  fori (i, 0, n) {
    int x; cin >> x;
    if (x == 0) ++a;
    if (x == 5) ++b;
  }


  int c = 0;
  ford (i, b, -1) 
    if ((i * 5) % 9 == 0) {
      c = i;
      break;
    }
   
  // trace(a, b, c);

  string ret;
  if (a == 0) ret = "-1";
  else if (c == 0) {
    ret = "0";
  } else {
    fori (i, 0, c) ret += '5';
    fori (i, 0, a) ret += '0';
  }
  
  output(ret); 
  return 0;
}

