#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
#define outret(val) cout << (val) << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl
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

// #define LOCAL_FILE

#define maxn 1000000
int primes[maxn];

void sieve(int n) {
  mst(primes, 0);  

  primes[0] = 1;
  primes[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (primes[i] == 1) continue;
    for (int j = i + i; j <= n; j += i)
      primes[j] = 1;
  }
}

vi path;
bool dfs(int n) {
  // trace(n);
  if (n == 1) return 0;
  if (n == 0) return 1;
  if (n < 0) return 0;
  fori (i, 2, maxn) {
    if (primes[i] == 0) {
      if (dfs(n - i)) {
        path.pb(i);
        return 1;
      }
    }
  }
  return 0;
}

int main(int argc, char** argv) {
#ifdef LOCAL_FILE
  // freopen("749a-input.txt", "rt", stdin);
  clock_t begin = clock();
#endif

  sieve(100000);
  int n; cin >> n >> ws;
  outret(n / 2);
  fori (i, 0, n / 2 - 1) {
    cout << 2 << " "; 
  }
  if (n % 2) cout << 3 << endl;
  else cout << 2 << endl;
  
#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cout << "elapsed(s): " << elapsed << endl;
#endif

  return 0;
}
