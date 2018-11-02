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
#define outret(v) cout << (v) << endl
#define output(ix, v) cout << "Case #" << (ix) << ": " << (v) << endl
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
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


int main(int argc, char** argv) {
  // while (1) {
  //   trace('a');
  // }

  int *p = nullptr;
  *p = 1;
  // int n, m; cin >> n >> m >> ws;
  // vi aa(m + 1, 0);
  // fori (i, 0, n) {
  //   string a, b;
  //   getline(cin, a);
  //   istringstream iss(a);
  //   int j = 0;
  //   while (getline(iss, b, ' ')) {
  //     if (j > 0) {
  //       aa[stoi(b)] = 1;
  //     }
  //     ++j;
  //   } 
  // }

  // pvi(aa, 1);

  // bool ok = 1;
  // fori (i, 1, m + 1) {
  //   if (aa[i] == 0) {
  //     ok = 0;
  //     break;
  //   }
  // }

  // outret(ok ? "YES" : "NO");

  return 0;
}

