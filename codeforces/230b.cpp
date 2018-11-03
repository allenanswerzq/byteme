#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define codejam(ix, v) cout << "Case #" << (ix) << ": " << (val) << endl

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

// TODO
bool prime(int inp) {
  if (((!(inp & 1)) && inp != 2 ) || (inp < 2) || (inp % 3 == 0 && inp != 3))
    return false;

    for (int k = 1; 36 * k * k - 12 * k < inp; ++k) {
      if ((inp % (6 * k + 1) == 0) || (inp % (6 * k - 1) == 0))
        return false;   
    }
  return true;
}

int main(int argc, char** argv) {
  int n; cin >> n >> ws;
  fori (i, 1, n + 1) {
    ll inp; cin >> inp;
    ll a = sqrt(inp);
    if (a * a == inp && prime(a)) output("YES");
    else output("NO");
  }

  return 0;
}
