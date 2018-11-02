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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define EXTERNAL
// TODO
int main(int argc, char** argv) {
#ifdef EXTERNAL
  string ss; cin >> ss;
  vi dp(sz(ss), 0);
  int ret = 0;
  fori (i, 0, sz(ss)) {
    if (ss[i] == 'A') {
      ford (j, i - 1, -1) 
        if (ss[j] == 'Q') ++dp[i];
    } else if (ss[i] == 'Q') {
      ford (j, i - 1, -1) {
        if (ss[j] == 'A') {
          if (dp[j]) dp[i] += dp[j];
        }
      }
      ret += dp[i];
    }
  }

  // string ss; cin >> ss;
  // vi dp(sz(ss), 0);
  // int ret, aa, bb;
  // ret = aa = bb = 0;
  // fori (i, 0, sz(ss)) {
  //   if (ss[i] == 'A') {
  //     bb += aa;
  //   } else if (ss[i] == 'Q') {
  //     ++aa;
  //     ret += bb;
  //   }
  // }

  // pvi(dp, 1);
  outret(ret);


#ifdef EXTERNAL
  return 0;
}

