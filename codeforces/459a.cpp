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

#define maxn 40000

int get(int x, int len) {
  int px = x + len;
  int nx = x - len;
  if (px <= 1000) return px;
  if (nx >= -1000) return nx;
  return maxn;
}

int main(int argc, char** argv) {
  int x1, y1, x2, y2; 
  int x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    int len = abs(y1 - y2);    
    x3 = get(x1, len); y3 = y1;
    x4 = get(x2, len); y4 = y2;
  } else if (y1 == y2) {
    int len = abs(x1 - x2);
    x3 = x1, y3 = get(y1, len);
    x4 = x2, y4 = get(y2, len);
  } else {
    int a = abs(x2 - x1);
    int b = abs(y2 - y1);
    if (a == b) {
      x3 = x2; y3 = y1;
      x4 = x1; y4 = y2;
    } else {
      x3 = maxn; y3 = maxn;
      x4 = maxn; y4 = maxn;
    }
  }

  if (x3 == maxn || y3 == maxn || x4 == maxn || y4 == maxn)
    output(-1);
  else 
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

  return 0;
}
