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

int main() {
  unordered_map<char, int> mp;
  mp['q'] = 9;
  mp['r'] = 5;
  mp['b'] = 3;
  mp['n'] = 3;
  mp['p'] = 1;
  mp['k'] = 0;
  int t = 8;
  int aa, bb;
  aa = bb = 0;
  fori (i, 1, t + 1) {
    string ss; cin >> ss;
    fori (j, 0, sz(ss)) {
      if (ss[j] == '.') continue;
      if (ss[j] == 'Q' || ss[j] == 'R' || ss[j] == 'B' ||
          ss[j] == 'N' || ss[j] == 'P' || ss[j] == 'K')
        aa += mp[tolower(ss[j])];
      else
        bb += mp[tolower(ss[j])];
    }
  }

  output(aa > bb ? "White" : aa == bb ? "Draw" : "Black");

  return 0;
}
